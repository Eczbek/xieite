#ifndef DETAIL_XIEITE_HEADER_MATH_BIG_INT
#	define DETAIL_XIEITE_HEADER_MATH_BIG_INT
#
#	include <bit>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <functional>
#	include <iterator>
#	include <limits>
#	include <ranges>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <utility>
#	include <vector>
#	include "../ctnr/num_str_config.hpp"
#	include "../fn/order_op.hpp"
#	include "../fn/range_cmp_op.hpp"
#	include "../math/abs.hpp"
#	include "../math/add_overflow.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/double_uint.hpp"
#	include "../math/neg.hpp"
#	include "../math/split_bool.hpp"
#	include "../math/ssize_t.hpp"
#	include "../math/sub_overflow.hpp"
#	include "../trait/rm_cv.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<std::unsigned_integral T = std::uint64_t>
	struct big_int {
	public:
		using type = T;

		template<std::integral U = xieite::ssize_t>
		[[nodiscard]] explicit(false) constexpr big_int(U x = 0) noexcept
		: neg(xieite::neg(x)) {
			xieite::try_unsign<U> abs = xieite::abs(x);
			do {
				this->data.push_back(static_cast<T>(abs));
				if constexpr (sizeof(U) > sizeof(T)) {
					abs >>= xieite::bit_size<T>;
				} else {
					break;
				}
			} while (abs);
		}

		template<typename U>
		[[nodiscard]] explicit constexpr big_int(const xieite::big_int<U>& x) noexcept
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
					this->data.back() |= limb << (shift_bytes * xieite::bit_size<char>);
					shift_bytes += sizeof(U);
				}
			} else {
				for (U limb : x.data) {
					std::size_t shift_bytes = 0;
					do {
						this->data.push_back(static_cast<T>(limb >> (shift_bytes * xieite::bit_size<char>)));
						shift_bytes += sizeof(T);
					} while (shift_bytes < sizeof(U));
				}
				this->trim();
			}
		}

		template<std::ranges::input_range R>
		requires(std::same_as<T, std::ranges::range_value_t<R>>)
		[[nodiscard]] explicit constexpr big_int(R&& range, bool neg = false) noexcept
		: data(std::ranges::begin(range), std::ranges::end(range)), neg(neg) {
			this->trim();
		}

		[[nodiscard]] explicit constexpr big_int(std::string_view str, xieite::ssize_t radix = 10, const xieite::num_str_config& config = {}) noexcept
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
			U result = 0;
			std::size_t i = 0;
			std::size_t j = 0;
			while (j < xieite::bit_size<U>) {
				result |= static_cast<U>(this->data[i]) << j;
				++i;
				j += xieite::bit_size<T>;
			}
			return this->neg ? -result : result;
		}

		[[nodiscard]] explicit(false) constexpr operator bool() const noexcept {
			return (this->data.size() > 1) || this->data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			using namespace xieite::order_op;
			using namespace xieite::range_cmp_op;
			return (r.neg <=> l.neg)
				| (l.neg
					? ((r.data.size() <=> l.data.size())
						| (std::views::reverse(r.data) <=> std::views::reverse(l.data)))
					: ((l.data.size() <=> r.data.size())
						| (std::views::reverse(l.data) <=> std::views::reverse(r.data))));
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<T>& l, U r) noexcept {
			return l <=> xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			return std::is_eq(l <=> r);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<T>& l, U r) noexcept {
			return l == xieite::big_int<T>(r);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator+(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
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
				carry = xieite::add_overflow(limb0, limb1, carry);
			}
			return xieite::big_int<T>(sum_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator+(const xieite::big_int<T>& l, U r) noexcept {
			return l + xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator+=(const xieite::big_int<T>& r) noexcept {
			return *this = *this + r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator+=(U r) noexcept {
			return *this += xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::big_int<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator-() const noexcept {
			return xieite::big_int<T>(this->data, !this->neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator-(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
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
				borrow = (i < (l.data.size() - 1)) && xieite::sub_overflow(l.data[i], limb, borrow);
			}
			return xieite::big_int<T>(diff_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator-(const xieite::big_int<T>& l, U r) noexcept {
			return l - xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator-=(const xieite::big_int<T>& r) noexcept {
			return *this = *this - r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator-=(U r) noexcept {
			return *this -= xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::big_int<T>& operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator*(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
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
			xieite::big_int<T> result;
			for (std::size_t i = l.data.size(); i--;) {
				if (!l.data[i]) {
					continue;
				}
				for (std::size_t j = r.data.size(); j--;) {
					if (!r.data[j]) {
						continue;
					}
					const auto prod = xieite::double_uint<T>(l.data[i]) * r.data[j];
					result += ((xieite::big_int<T>(prod.hi) << xieite::bit_size<T>) | prod.lo) << (xieite::big_int<T>(i) << std::bit_width(xieite::bit_size<T> - 1)) << (xieite::big_int<T>(j) << std::bit_width(xieite::bit_size<T> - 1));
				}
			}
			result.neg = l.neg != r.neg;
			return result;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator*(const xieite::big_int<T>& l, U r) noexcept {
			return l * xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator*=(const xieite::big_int<T>& r) noexcept {
			return *this = *this * r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator*=(U r) noexcept {
			return *this *= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator/(const xieite::big_int<T>& l, const xieite::big_int<T>& r) {
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
			const xieite::big_int<T> l_abs = l.abs();
			const xieite::big_int<T> r_abs = r.abs();
			if (!l || (l_abs < r_abs)) {
				return 0;
			}
			if (l_abs == r_abs) {
				return xieite::split_bool(same_sign);
			}
			if (r.pow_of_2()) {
				if (same_sign) {
					return l_abs >> r.log2();
				}
				return -(l_abs >> r.log2());
			}
			xieite::big_int<T> rem;
			xieite::big_int<T> quot;
			rem.data.resize(l.data.size(), 0);
			quot.data.resize(l.data.size(), 0);
			for (std::size_t i = l.data.size(); i--;) {
				for (std::size_t j = xieite::bit_size<T>; j--;) {
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
		[[nodiscard]] friend constexpr xieite::big_int<T> operator/(const xieite::big_int<T>& l, U r) {
			return l / xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T> operator/=(const xieite::big_int<T>& r) {
			return *this = *this / r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T> operator/=(U r) {
			return *this /= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator%(const xieite::big_int<T>& l, const xieite::big_int<T>& r) {
			if (!r) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			const xieite::big_int<T> l_abs = l.abs();
			const xieite::big_int<T> r_abs = r.abs();
			if (!l || (r_abs == 1) || (l_abs == r_abs)) {
				return 0;
			}
			if (r_abs.pow_of_2()) {
				return (l_abs & (r_abs - 1)) * xieite::split_bool(!l.neg);
			}
			if (l_abs < r_abs) {
				return l;
			}
			xieite::big_int<T> rem;
			for (T limb : std::views::reverse(l.data)) {
				for (std::size_t j = xieite::bit_size<T>; j--;) {
					rem <<= 1;
					rem.data[0] |= (limb >> j) & 1;
					rem -= r_abs * (rem >= r_abs);
				}
			}
			rem.neg = l.neg;
			return rem;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator%(const xieite::big_int<T>& l, U r) {
			return l % xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T> operator%=(const xieite::big_int<T>& r) {
			return *this = *this % r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T> operator%=(U r) {
			return *this %= xieite::big_int<T>(r);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator&(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			return xieite::big_int<T>::bit_op(l, r, std::bit_and());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator&(const xieite::big_int<T>& l, U r) noexcept {
			return l & xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator&=(const xieite::big_int<T>& r) noexcept {
			return *this = *this & r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator&=(U r) noexcept {
			return *this &= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator|(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			return xieite::big_int<T>::bit_op(l, r, std::bit_or());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator|(const xieite::big_int<T>& l, U r) noexcept {
			return l | xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator|=(const xieite::big_int<T>& r) noexcept {
			return *this = *this | r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator|=(U r) noexcept {
			return *this |= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator^(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			return xieite::big_int<T>::bit_op(l, r, std::bit_xor());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator^(const xieite::big_int<T>& l, U r) noexcept {
			return l ^ xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator^=(const xieite::big_int<T>& r) noexcept {
			return *this = *this ^ r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator^=(U r) noexcept {
			return *this ^= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator<<(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			if (!l || !r) {
				return l;
			}
			if (r.neg) {
				return l >> -r;
			}
			const std::size_t data_shift = static_cast<std::size_t>(r) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(r) & (xieite::bit_size<T> - 1);
			auto result_data = std::vector<T>(data_shift, 0);
			result_data.insert(result_data.end(), l.data.begin(), l.data.end());
			if (bits_shift) {
				T carry = 0;
				for (std::size_t i = 0; i < l.data.size(); ++i) {
					result_data[i + data_shift] = (l.data[i] << bits_shift) | carry;
					carry = l.data[i] >> (xieite::bit_size<T> - bits_shift);
				}
				if (carry) {
					result_data.push_back(carry);
				}
			}
			return xieite::big_int<T>(result_data, l.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator<<(const xieite::big_int<T>& l, U r) noexcept {
			return l << xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator<<=(const xieite::big_int<T>& r) noexcept {
			return *this = *this << r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator<<=(U r) noexcept {
			return *this <<= xieite::big_int<T>(r);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator>>(const xieite::big_int<T>& l, const xieite::big_int<T>& r) noexcept {
			if (!l || !r) {
				return l;
			}
			if (r.neg) {
				return l >> -r;
			}
			const std::size_t data_shift = static_cast<std::size_t>(r) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(r) & (xieite::bit_size<T> - 1);
			if (data_shift >= l.data.size()) {
				return 0;
			}
			auto result_data = std::vector<T>(std::ranges::next(l.data.begin(), static_cast<xieite::ssize_t>(data_shift), l.data.end()), l.data.end());
			if (bits_shift) {
				T carry = 0;
				for (T& limb : std::views::reverse(result_data)) {
					carry = std::exchange(limb, (limb >> bits_shift) | carry) << (xieite::bit_size<T> - bits_shift);
				}
			}
			return xieite::big_int<T>(result_data, l.neg) - l.neg;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator>>(const xieite::big_int<T>& l, U r) noexcept {
			return l >> xieite::big_int<T>(r);
		}

		constexpr xieite::big_int<T>& operator>>=(const xieite::big_int<T>& r) noexcept {
			return *this = *this >> r;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator>>=(U r) noexcept {
			return *this >>= xieite::big_int<T>(r);
		}

		[[nodiscard]] constexpr xieite::big_int<T> abs() const noexcept {
			return xieite::big_int<T>(this->data);
		}

		[[nodiscard]] constexpr xieite::big_int<T> pow(xieite::big_int<T> exp) const {
			if ((*this == 1) || (exp == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * xieite::split_bool(exp & 1);
			}
			if (!*this || !exp) {
				if (exp.neg) {
					throw std::out_of_range("must not take power of zero to negative exponent");
				}
				return !exp;
			}
			xieite::big_int<T> base = *this;
			xieite::big_int<T> result = 1;
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
		[[nodiscard]] constexpr xieite::big_int<T> pow(U exp) const {
			return this->pow(xieite::big_int<T>(exp));
		}

		[[nodiscard]] constexpr xieite::big_int<T> root(const xieite::big_int<T>& deg) const {
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
			xieite::big_int<T> foo = deg - 1;
			xieite::big_int<T> bar = *this;
			xieite::big_int<T> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.pow(foo)) / deg;
			}
			return baz;
		}

		template<std::integral U>
		[[nodiscard]] constexpr xieite::big_int<T> root(U deg) const {
			return this->root(xieite::big_int<T>(deg));
		}

		[[nodiscard]] constexpr xieite::big_int<T> log(const xieite::big_int<T>& base) const {
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
		[[nodiscard]] constexpr xieite::big_int<T> log(U base) const {
			return this->log(xieite::big_int<T>(base));
		}

		[[nodiscard]] constexpr std::string str(xieite::ssize_t radix = 10, xieite::num_str_config config = {}) const noexcept {
			if (!*this || !radix) {
				return std::string(1, config.digit[0]);
			}
			std::string result;
			xieite::big_int<T> x = this->abs();
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
					xieite::ssize_t idx = static_cast<xieite::ssize_t>(x % radix);
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

		[[nodiscard]] static constexpr xieite::big_int<T> bit_op(xieite::big_int<T> l, xieite::big_int<T> r, auto fn) noexcept {
			const bool l_neg = l.neg;
			const bool r_neg = r.neg;
			l += l_neg;
			r += r_neg;
			xieite::big_int<T> result;
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
			const xieite::big_int<T> abs = this->abs();
			return abs && !(abs & (abs - 1));
		}

		[[nodiscard]] constexpr xieite::big_int<T> log2() const noexcept {
			return xieite::big_int<T>(xieite::bit_size<T>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}
	};
}

#endif
