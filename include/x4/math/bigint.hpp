#pragma once

#include <bit>
#include <compare>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <limits>
#include <ranges>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include "../ctnr/nstrcfg.hpp"
#include "../fn/ordop.hpp"
#include "../fn/rangecmpop.hpp"
#include "../math/abs.hpp"
#include "../math/addovf.hpp"
#include "../math/bits.hpp"
#include "../math/duint.hpp"
#include "../math/neg.hpp"
#include "../math/splitb.hpp"
#include "../math/z.hpp"
#include "../math/subovf.hpp"
#include "../meta/tryunsign.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<std::unsigned_integral T = std::uint64_t>
	struct bigint {
	public:
		using type = T;

		template<std::integral U = int>
		[[nodiscard]] explicit(false) constexpr bigint(U x = 0) noexcept
		: neg(x4::neg(x)) {
			x4::tryunsign<U> abs = x4::abs(x);
			do {
				this->data.push_back(static_cast<T>(abs));
				if constexpr (sizeof(U) > sizeof(T)) {
					abs >>= x4::bits<T>;
				} else {
					break;
				}
			} while (abs);
		}

		template<typename U>
		[[nodiscard]] explicit constexpr bigint(const x4::bigint<U>& x) noexcept
		: neg(x.neg) {
			if constexpr (sizeof(T) == sizeof(U)) {
				this->data = x.data;
			} else if constexpr (sizeof(T) > sizeof(U)) {
				std::size_t shift_bytes = sizeof(T);
				for (U limb : x.data) {
					if (shift_bytes >= sizeof(T)) {
						shift_bytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= limb << (shift_bytes * x4::bits<char>);
					shift_bytes += sizeof(U);
				}
			} else {
				for (U limb : x.data) {
					std::size_t shift_bytes = 0;
					do {
						this->data.push_back(static_cast<T>(limb >> (shift_bytes * x4::bits<char>)));
						shift_bytes += sizeof(T);
					} while (shift_bytes < sizeof(U));
				}
				this->trim();
			}
		}

		template<std::ranges::input_range R>
		requires(std::same_as<T, std::ranges::range_value_t<R>>)
		[[nodiscard]] explicit constexpr bigint(R&& range, bool neg = false) noexcept
		: data(std::ranges::begin(range), std::ranges::end(range)), neg(neg) {
			this->trim();
		}

		[[nodiscard]] explicit constexpr bigint(std::string_view str, x4::z radix = 10, x4::nstrcfg config = {}) noexcept
		: neg(false) {
			*this = 0;
			if (!radix) {
				return;
			}
			const bool neg = config.minus.contains(str[0]);
			str.remove_prefix(neg || config.plus.contains(str[0]));
			for (char c : str) {
				const std::size_t digit = config.digit.find(c);
				if (digit == std::string::npos) {
					break;
				}
				*this = *this * radix + digit;
			}
			this->neg = neg;
		}

		template<std::integral U>
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			if constexpr (std::same_as<x4::rmcv<U>, bool>) {
				return (this->data.size() > 1) || this->data[0];
			} else {
				U result = 0;
				std::size_t i = 0;
				std::size_t j = 0;
				while (j < x4::bits<U>) {
					result |= static_cast<U>(this->data[i]) << j;
					++i;
					j += x4::bits<T>;
				}
				return this->neg ? -result : result;
			}
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			using namespace x4::ordop;
			using namespace x4::rangecmpop;
			return (r.neg <=> l.neg)
				| (l.neg
					? ((r.data.size() <=> l.data.size())
						| (std::views::reverse(r.data) <=> std::views::reverse(l.data)))
					: ((l.data.size() <=> r.data.size())
						| (std::views::reverse(l.data) <=> std::views::reverse(r.data))));
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const x4::bigint<T>& l, U r) noexcept {
			return l <=> x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr bool operator==(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			return std::is_eq(l <=> r);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr bool operator==(const x4::bigint<T>& l, U r) noexcept {
			return l == x4::bigint<T>(r);
		}

		[[nodiscard]] constexpr x4::bigint<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator+(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			if (!l) {
				return r;
			}
			if (!r) {
				return l;
			}
			if (l.neg != r.neg) {
				return l - (-r);
			}
			std::vector<T> sum_data;
			bool carry = false;
			for (std::size_t i = 0; (i < l.data.size()) || (i < r.data.size()) || carry; ++i) {
				const T limb0 = (i < l.data.size()) ? l.data[i] : 0;
				const T limb1 = (i < r.data.size()) ? r.data[i] : 0;
				sum_data.push_back(limb0 + limb1 + carry);
				carry = x4::addovf(limb0, limb1, carry);
			}
			return x4::bigint<T>(sum_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator+(const x4::bigint<T>& l, U r) noexcept {
			return l + x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator+=(const x4::bigint<T>& r) noexcept {
			return *this = *this + r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator+=(U r) noexcept {
			return *this += x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr x4::bigint<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr x4::bigint<T> operator-() const noexcept {
			return x4::bigint<T>(this->data, !this->neg);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator-(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			if (!r) {
				return l;
			}
			if (!l) {
				return -r;
			}
			if (l.neg != r.neg) {
				return l + (-r);
			}
			if (l.neg ? (l > r) : (l < r)) {
				return -(r - l);
			}
			if (l == r) {
				return 0;
			}
			std::vector<T> diff_data;
			bool borrow = false;
			for (std::size_t i = 0; (i < r.data.size()) || borrow; ++i) {
				const T limb = (i < r.data.size()) ? r.data[i] : 0;
				diff_data.push_back(l.data[i] - limb - borrow);
				borrow = (i < (l.data.size() - 1)) && x4::subovf(l.data[i], limb, borrow);
			}
			return x4::bigint<T>(diff_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator-(const x4::bigint<T>& l, U r) noexcept {
			return l - x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator-=(const x4::bigint<T>& r) noexcept {
			return *this = *this - r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator-=(U r) noexcept {
			return *this -= x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr x4::bigint<T>& operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator*(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			if (!l || !r) {
				return 0;
			}
			const bool same_sign = l.neg == r.neg;
			if ((l == 1) || (l == -1)) {
				return same_sign ? r : -r;
			}
			if ((r == 1) || (r == -1)) {
				return same_sign ? l : -l;
			}
			if (l.pow_of_2()) {
				if (same_sign) {
					return r.abs() << l.log2();
				}
				return -(r.abs() << l.log2());
			}
			if (r.pow_of_2()) {
				if (same_sign) {
					return l.abs() << r.log2();
				}
				return -(l.abs() << r.log2());
			}
			x4::bigint<T> result;
			for (std::size_t i = l.data.size(); i--;) {
				if (!l.data[i]) {
					continue;
				}
				for (std::size_t j = r.data.size(); j--;) {
					if (!r.data[j]) {
						continue;
					}
					const auto prod = x4::duint<T>(l.data[i]) * r.data[j];
					result += ((x4::bigint<T>(prod.hi) << x4::bits<T>) | prod.lo) << (x4::bigint<T>(i) << std::bit_width(x4::bits<T> - 1)) << (x4::bigint<T>(j) << std::bit_width(x4::bits<T> - 1));
				}
			}
			result.neg = l.neg != r.neg;
			return result;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator*(const x4::bigint<T>& l, U r) noexcept {
			return l * x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator*=(const x4::bigint<T>& r) noexcept {
			return *this = *this * r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator*=(U r) noexcept {
			return *this *= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator/(const x4::bigint<T>& l, const x4::bigint<T>& r) {
			if (!r) {
				throw std::out_of_range("must not divide by zero");
			}
			if ((l.data.size() < 2) && (r.data.size() < 2)) {
				return l.data[0] / r.data[0];
			}
			const bool same_sign = l.neg == r.neg;
			if ((r == 1) || (r == -1)) {
				return same_sign ? l : -l;
			}
			const x4::bigint<T> l_abs = l.abs();
			const x4::bigint<T> r_abs = r.abs();
			if (!l || (l_abs < r_abs)) {
				return 0;
			}
			if (l_abs == r_abs) {
				return x4::splitb(same_sign);
			}
			if (r.pow_of_2()) {
				if (same_sign) {
					return l_abs >> r.log2();
				}
				return -(l_abs >> r.log2());
			}
			x4::bigint<T> rem;
			x4::bigint<T> quot;
			rem.data.resize(l.data.size(), 0);
			quot.data.resize(l.data.size(), 0);
			for (std::size_t i = l.data.size(); i--;) {
				for (std::size_t j = x4::bits<T>; j--;) {
					rem <<= 1;
					rem.data[0] |= (l.data[i] >> j) & 1;
					const bool bit = rem >= r_abs;
					rem -= r_abs * bit;
					quot.data[i] |= static_cast<T>(bit) << j;
				}
			}
			quot.neg = !same_sign;
			quot.trim();
			return quot;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator/(const x4::bigint<T>& l, U r) {
			return l / x4::bigint<T>(r);
		}

		constexpr x4::bigint<T> operator/=(const x4::bigint<T>& r) {
			return *this = *this / r;
		}

		template<std::integral U>
		constexpr x4::bigint<T> operator/=(U r) {
			return *this /= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator%(const x4::bigint<T>& l, const x4::bigint<T>& r) {
			if (!r) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			const x4::bigint<T> l_abs = l.abs();
			const x4::bigint<T> r_abs = r.abs();
			if (!l || (r_abs == 1) || (l_abs == r_abs)) {
				return 0;
			}
			if (r_abs.pow_of_2()) {
				return (l_abs & (r_abs - 1)) * x4::splitb(!l.neg);
			}
			if (l_abs < r_abs) {
				return l;
			}
			x4::bigint<T> rem;
			for (T limb : std::views::reverse(l.data)) {
				for (std::size_t j = x4::bits<T>; j--;) {
					rem <<= 1;
					rem.data[0] |= (limb >> j) & 1;
					rem -= r_abs * (rem >= r_abs);
				}
			}
			rem.neg = l.neg;
			return rem;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator%(const x4::bigint<T>& l, U r) {
			return l % x4::bigint<T>(r);
		}

		constexpr x4::bigint<T> operator%=(const x4::bigint<T>& r) {
			return *this = *this % r;
		}

		template<std::integral U>
		constexpr x4::bigint<T> operator%=(U r) {
			return *this %= x4::bigint<T>(r);
		}

		[[nodiscard]] constexpr x4::bigint<T> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator&(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			return x4::bigint<T>::bit_op(l, r, std::bit_and());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator&(const x4::bigint<T>& l, U r) noexcept {
			return l & x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator&=(const x4::bigint<T>& r) noexcept {
			return *this = *this & r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator&=(U r) noexcept {
			return *this &= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator|(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			return x4::bigint<T>::bit_op(l, r, std::bit_or());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator|(const x4::bigint<T>& l, U r) noexcept {
			return l | x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator|=(const x4::bigint<T>& r) noexcept {
			return *this = *this | r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator|=(U r) noexcept {
			return *this |= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator^(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			return x4::bigint<T>::bit_op(l, r, std::bit_xor());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator^(const x4::bigint<T>& l, U r) noexcept {
			return l ^ x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator^=(const x4::bigint<T>& r) noexcept {
			return *this = *this ^ r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator^=(U r) noexcept {
			return *this ^= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator<<(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			if (!l || !r) {
				return l;
			}
			if (r.neg) {
				return l >> -r;
			}
			const std::size_t data_shift = static_cast<std::size_t>(r) >> static_cast<std::size_t>(std::bit_width(x4::bits<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(r) & (x4::bits<T> - 1);
			auto result_data = std::vector<T>(data_shift, 0);
			result_data.insert(result_data.end(), l.data.begin(), l.data.end());
			if (bits_shift) {
				T carry = 0;
				for (std::size_t i = 0; i < l.data.size(); ++i) {
					result_data[i + data_shift] = (l.data[i] << bits_shift) | carry;
					carry = l.data[i] >> (x4::bits<T> - bits_shift);
				}
				if (carry) {
					result_data.push_back(carry);
				}
			}
			return x4::bigint<T>(result_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator<<(const x4::bigint<T>& l, U r) noexcept {
			return l << x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator<<=(const x4::bigint<T>& r) noexcept {
			return *this = *this << r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator<<=(U r) noexcept {
			return *this <<= x4::bigint<T>(r);
		}

		[[nodiscard]] friend constexpr x4::bigint<T> operator>>(const x4::bigint<T>& l, const x4::bigint<T>& r) noexcept {
			if (!l || !r) {
				return l;
			}
			if (r.neg) {
				return l >> -r;
			}
			const std::size_t data_shift = static_cast<std::size_t>(r) >> static_cast<std::size_t>(std::bit_width(x4::bits<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(r) & (x4::bits<T> - 1);
			if (data_shift >= l.data.size()) {
				return 0;
			}
			auto result_data = std::vector<T>(std::ranges::next(l.data.begin(), static_cast<x4::z>(data_shift), l.data.end()), l.data.end());
			if (bits_shift) {
				T carry = 0;
				for (T& limb : std::views::reverse(result_data)) {
					carry = std::exchange(limb, (limb >> bits_shift) | carry) << (x4::bits<T> - bits_shift);
				}
			}
			return x4::bigint<T>(result_data, l.neg) - l.neg;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr x4::bigint<T> operator>>(const x4::bigint<T>& l, U r) noexcept {
			return l >> x4::bigint<T>(r);
		}

		constexpr x4::bigint<T>& operator>>=(const x4::bigint<T>& r) noexcept {
			return *this = *this >> r;
		}

		template<std::integral U>
		constexpr x4::bigint<T>& operator>>=(U r) noexcept {
			return *this >>= x4::bigint<T>(r);
		}

		[[nodiscard]] constexpr x4::bigint<T> abs() const noexcept {
			return x4::bigint<T>(this->data);
		}

		[[nodiscard]] constexpr x4::bigint<T> pow(x4::bigint<T> exp) const {
			if ((*this == 1) || (exp == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * x4::splitb(!!(exp & 1));
			}
			if (!*this || !exp) {
				if (exp.neg) {
					throw std::out_of_range("must not take power of zero to negative exponent");
				}
				return !exp;
			}
			x4::bigint<T> base = *this;
			x4::bigint<T> result = 1;
			while (exp > 1) {
				if (exp & 1) {
					result *= base;
					exp = (exp - 1) >> 1;
				} else {
					exp >>= 1;
				}
				base *= base;
			}
			return result * base;
		}

		template<std::integral U>
		[[nodiscard]] constexpr x4::bigint<T> pow(U exp) const {
			return this->pow(x4::bigint<T>(exp));
		}

		[[nodiscard]] constexpr x4::bigint<T> root(const x4::bigint<T>& deg) const {
			if (this->neg) {
				throw std::out_of_range("must not take root of negative radicand");
			}
			if (!deg) {
				throw std::out_of_range("must not take root to zeroth degree");
			}
			if (*this == 1) {
				return *this;
			}
			if (deg.neg) {
				return 0;
			}
			x4::bigint<T> foo = deg - 1;
			x4::bigint<T> bar = *this;
			x4::bigint<T> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.pow(foo)) / deg;
			}
			return baz;
		}

		template<std::integral U>
		[[nodiscard]] constexpr x4::bigint<T> root(U deg) const {
			return this->root(x4::bigint<T>(deg));
		}

		[[nodiscard]] constexpr x4::bigint<T> log(const x4::bigint<T>& base) const {
			if (!base) {
				return 0;
			}
			if (this->neg) {
				throw std::out_of_range("must not take logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw std::out_of_range("must not take logarithm to unary base");
			}
			if (base.neg) {
				throw std::out_of_range("must not take logarithm to negative base");
			}
			return this->log2() / base.log2();
		}

		template<std::integral U>
		[[nodiscard]] constexpr x4::bigint<T> log(U base) const {
			return this->log(x4::bigint<T>(base));
		}

		[[nodiscard]] constexpr std::string str(x4::z radix = 10, x4::nstrcfg config = {}) const noexcept {
			if (!*this || !radix) {
				return std::string(1, config.digit[0]);
			}
			std::string result;
			x4::bigint<T> x = this->abs();
			if (radix == 1) {
				result = std::string(static_cast<std::size_t>(x), config.digit[1]);
			} else if (radix == -1) {
				result = config.digit[1];
				for (std::size_t length = static_cast<std::size_t>(x); --length;) {
					result += config.digit[0];
					result += config.digit[1];
				}
			} else {
				do {
					x4::z idx = static_cast<x4::z>(x % radix);
					x /= radix;
					if (idx < 0) {
						idx += radix;
						++x;
					}
					result.insert(0, 1, config.digit[static_cast<std::size_t>(idx) * (static_cast<std::size_t>(idx) < config.digit.size())]);
				} while (x);
			}
			if (*this < 0) {
				result.insert(0, 1, config.minus[0]);
			}
			return result;
		}

	private:
		std::vector<T> data;
		bool neg;

		[[nodiscard]] static constexpr x4::bigint<T> bit_op(x4::bigint<T> l, x4::bigint<T> r, auto fn) noexcept {
			const bool l_neg = l.neg;
			const bool r_neg = r.neg;
			l += l_neg;
			r += r_neg;
			x4::bigint<T> result;
			result.data.clear();
			result.neg = fn(l_neg, r_neg);
			for (std::size_t i = 0; (i < l.data.size()) || (i < r.data.size()); ++i) {
				const T limb = fn(
					(i < l.data.size())
						? (l_neg ? ~l.data[i] : l.data[i])
						: (std::numeric_limits<T>::max() * l_neg),
					(i < r.data.size())
						? (r_neg ? ~r.data[i] : r.data[i])
						: (std::numeric_limits<T>::max() * r_neg)
				);
				result.data.push_back(result.neg ? ~limb : limb);
			}
			return result - result.neg;
		}

		constexpr void trim() noexcept {
			std::size_t size = this->data.size();
			while ((size > 1) && !this->data.back()) {
				this->data.pop_back();
				--size;
			}
			if (!size) {
				this->data.push_back(0);
			}
			if (!*this) {
				this->neg = false;
			}
		}

		[[nodiscard]] constexpr bool pow_of_2() const noexcept {
			const x4::bigint<T> abs = this->abs();
			return abs && !(abs & (abs - 1));
		}

		[[nodiscard]] constexpr x4::bigint<T> log2() const noexcept {
			return x4::bigint<T>(x4::bits<T>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}
	};
}
