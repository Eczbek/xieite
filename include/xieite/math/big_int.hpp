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
#	include "../data/number_str_config.hpp"
#	include "../fn/range_cmp.hpp"
#	include "../math/abs.hpp"
#	include "../math/add_overflow.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/neg.hpp"
#	include "../math/split_bool.hpp"
#	include "../math/ssize_t.hpp"
#	include "../math/sub_overflow.hpp"
#	include "../math/wide_uint.hpp"

namespace xieite {
	template<std::unsigned_integral UInt = std::uint64_t>
	struct big_int {
	public:
		using type = UInt;

		template<std::integral Int = UInt>
		[[nodiscard]] explicit(false) constexpr big_int(Int x = 0) noexcept
		: neg(xieite::neg(x)) {
			auto abs = xieite::abs(x);
			do {
				this->data.push_back(static_cast<UInt>(abs));
				if constexpr (sizeof(x) > sizeof(UInt)) {
					abs >>= xieite::bit_size<UInt>;
				} else {
					break;
				}
			} while (abs);
		}

		template<typename OtherUInt>
		[[nodiscard]] explicit constexpr big_int(const xieite::big_int<OtherUInt>& x) noexcept
		: neg(x.neg) {
			if constexpr (sizeof(UInt) == sizeof(OtherUInt)) {
				this->data = x.data;
			} else if constexpr (sizeof(UInt) > sizeof(OtherUInt)) {
				std::size_t shift_bytes = sizeof(UInt);
				for (OtherUInt limb : x.data) {
					if (shift_bytes >= sizeof(UInt)) {
						shift_bytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= limb << (shift_bytes * xieite::bit_size<char>);
					shift_bytes += sizeof(OtherUInt);
				}
			} else {
				for (OtherUInt limb : x.data) {
					std::size_t shift_bytes = 0;
					do {
						this->data.push_back(static_cast<UInt>(limb >> (shift_bytes * xieite::bit_size<char>)));
						shift_bytes += sizeof(UInt);
					} while (shift_bytes < sizeof(OtherUInt));
				}
				this->trim();
			}
		}

		template<std::ranges::input_range Range>
		requires(std::same_as<UInt, std::ranges::range_value_t<Range>>)
		[[nodiscard]] explicit constexpr big_int(Range&& range, bool neg = false) noexcept
		: data(std::ranges::begin(range), std::ranges::end(range)), neg(neg) {
			this->trim();
		}

		[[nodiscard]] explicit constexpr big_int(std::string_view strv, xieite::ssize_t radix = 10, const xieite::number_str_config& config = {}) noexcept
		: neg(false) {
			*this = 0;
			if (!radix) {
				return;
			}
			const bool neg = config.minus.contains(strv[0]);
			strv.remove_prefix(neg || config.plus.contains(strv[0]));
			for (char c : strv) {
				if (const std::size_t digit = config.digits.find(c); digit != std::string_view::npos) {
					(*this *= radix) += digit;
					continue;
				}
				break;
			}
			this->neg = neg;
		}

		template<std::integral Int>
		[[nodiscard]] explicit constexpr operator Int() const noexcept {
			Int result = 0;
			std::size_t i = 0;
			std::size_t j = 0;
			while (j < xieite::bit_size<Int>) {
				result |= static_cast<Int>(this->data[i]) << j;
				++i;
				j += xieite::bit_size<UInt>;
			}
			return this->neg ? -result : result;
		}

		[[nodiscard]] explicit(false) constexpr operator bool() const noexcept {
			return (this->data.size() > 1) || this->data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			std::strong_ordering order = lhs.neg <=> rhs.neg;
			void(!std::is_eq(order) || (lhs.neg
				? (!std::is_eq(order = rhs.data.size() <=> lhs.data.size())
					|| (void(order = xieite::range_cmp(std::views::reverse(rhs.data), std::views::reverse(lhs.data))), true))
				: (!std::is_eq(order = lhs.data.size() <=> rhs.data.size())
					|| (void(order = xieite::range_cmp(std::views::reverse(lhs.data), std::views::reverse(rhs.data))), true))));
			return order;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs <=> xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs == xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator+(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			if (!lhs) {
				return rhs;
			}
			if (!rhs) {
				return lhs;
			}
			if (lhs.neg != rhs.neg) {
				return lhs - (-rhs);
			}
			std::vector<UInt> sum_data;
			bool carry = false;
			for (std::size_t i = 0; (i < lhs.data.size()) || (i < rhs.data.size()) || carry; ++i) {
				const UInt limb0 = (i < lhs.data.size()) ? lhs.data[i] : 0;
				const UInt limb1 = (i < rhs.data.size()) ? rhs.data[i] : 0;
				sum_data.push_back(limb0 + limb1 + carry);
				carry = xieite::add_overflow(limb0, limb1, carry);
			}
			return xieite::big_int<UInt>(sum_data, lhs.neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator+(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs + xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator+=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::big_int<UInt>& operator+=(std::integral auto rhs) noexcept {
			return *this += xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::big_int<UInt> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> operator-() const noexcept {
			return xieite::big_int<UInt>(this->data, !this->neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator-(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			if (!rhs) {
				return lhs;
			}
			if (!lhs) {
				return -rhs;
			}
			if (lhs.neg != rhs.neg) {
				return lhs + (-rhs);
			}
			if (lhs.neg ? (lhs > rhs) : (lhs < rhs)) {
				return -(rhs - lhs);
			}
			if (lhs == rhs) {
				return 0;
			}
			std::vector<UInt> diff_data;
			bool borrow = false;
			for (std::size_t i = 0; (i < rhs.data.size()) || borrow; ++i) {
				const UInt limb = (i < rhs.data.size()) ? rhs.data[i] : 0;
				diff_data.push_back(lhs.data[i] - limb - borrow);
				borrow = (i < (lhs.data.size() - 1)) && xieite::sub_overflow(lhs.data[i], limb, borrow);
			}
			return xieite::big_int<UInt>(diff_data, lhs.neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator-(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs - xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator-=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::big_int<UInt>& operator-=(std::integral auto rhs) noexcept {
			return *this -= xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::big_int<UInt>& operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator*(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			if (!lhs || !rhs) {
				return 0;
			}
			const bool same_sign = lhs.neg == rhs.neg;
			if ((lhs == 1) || (lhs == -1)) {
				return same_sign ? rhs : -rhs;
			}
			if ((rhs == 1) || (rhs == -1)) {
				return same_sign ? lhs : -lhs;
			}
			if (lhs.pow_of_2()) {
				if (same_sign) {
					return rhs.abs() << lhs.log2();
				}
				return -(rhs.abs() << lhs.log2());
			}
			if (rhs.pow_of_2()) {
				if (same_sign) {
					return lhs.abs() << rhs.log2();
				}
				return -(lhs.abs() << rhs.log2());
			}
			xieite::big_int<UInt> result;
			for (std::size_t i = lhs.data.size(); i--;) {
				if (!lhs.data[i]) {
					continue;
				}
				for (std::size_t j = rhs.data.size(); j--;) {
					if (!rhs.data[j]) {
						continue;
					}
					const auto prod = xieite::wide_uint<UInt>(lhs.data[i]) * rhs.data[j];
					result += ((xieite::big_int<UInt>(prod.hi) << xieite::bit_size<UInt>) | prod.lo) << (xieite::big_int<UInt>(i) << std::bit_width(xieite::bit_size<UInt> - 1)) << (xieite::big_int<UInt>(j) << std::bit_width(xieite::bit_size<UInt> - 1));
				}
			}
			result.neg = lhs.neg != rhs.neg;
			return result;
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator*(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs * xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator*=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this * rhs;
		}

		constexpr xieite::big_int<UInt>& operator*=(std::integral auto rhs) noexcept {
			return *this *= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator/(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) {
			if (!rhs) {
				throw std::out_of_range("must not divide by zero");
			}
			if ((lhs.data.size() < 2) && (rhs.data.size() < 2)) {
				return lhs.data[0] / rhs.data[0];
			}
			const bool same_sign = lhs.neg == rhs.neg;
			if ((rhs == 1) || (rhs == -1)) {
				return same_sign ? lhs : -lhs;
			}
			const xieite::big_int<UInt> l_abs = lhs.abs();
			const xieite::big_int<UInt> r_abs = rhs.abs();
			if (!lhs || (l_abs < r_abs)) {
				return 0;
			}
			if (l_abs == r_abs) {
				return xieite::split_bool(same_sign);
			}
			if (rhs.pow_of_2()) {
				if (same_sign) {
					return l_abs >> rhs.log2();
				}
				return -(l_abs >> rhs.log2());
			}
			xieite::big_int<UInt> rem;
			xieite::big_int<UInt> quot;
			rem.data.resize(lhs.data.size(), 0);
			quot.data.resize(lhs.data.size(), 0);
			for (std::size_t i = lhs.data.size(); i--;) {
				for (std::size_t j = xieite::bit_size<UInt>; j--;) {
					rem <<= 1;
					rem.data[0] |= (lhs.data[i] >> j) & 1;
					const bool bit = rem >= r_abs;
					rem -= r_abs * bit;
					quot.data[i] |= static_cast<UInt>(bit) << j;
				}
			}
			quot.neg = !same_sign;
			quot.trim();
			return quot;
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator/(const xieite::big_int<UInt>& lhs, std::integral auto rhs) {
			return lhs / xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt> operator/=(const xieite::big_int<UInt>& rhs) {
			return *this = *this / rhs;
		}

		constexpr xieite::big_int<UInt> operator/=(std::integral auto rhs) {
			return *this /= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator%(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) {
			if (!rhs) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			const xieite::big_int<UInt> l_abs = lhs.abs();
			const xieite::big_int<UInt> r_abs = rhs.abs();
			if (!lhs || (r_abs == 1) || (l_abs == r_abs)) {
				return 0;
			}
			if (r_abs.pow_of_2()) {
				return (l_abs & (r_abs - 1)) * xieite::split_bool(!lhs.neg);
			}
			if (l_abs < r_abs) {
				return lhs;
			}
			xieite::big_int<UInt> rem;
			for (UInt limb : std::views::reverse(lhs.data)) {
				for (std::size_t j = xieite::bit_size<UInt>; j--;) {
					rem <<= 1;
					rem.data[0] |= (limb >> j) & 1;
					rem -= r_abs * (rem >= r_abs);
				}
			}
			rem.neg = lhs.neg;
			return rem;
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator%(const xieite::big_int<UInt>& lhs, std::integral auto rhs) {
			return lhs % xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt> operator%=(const xieite::big_int<UInt>& rhs) {
			return *this = *this % rhs;
		}

		constexpr xieite::big_int<UInt> operator%=(std::integral auto rhs) {
			return *this %= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator&(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			return xieite::big_int<UInt>::bit_op(lhs, rhs, std::bit_and());
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator&(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs & xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator&=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this & rhs;
		}

		constexpr xieite::big_int<UInt>& operator&=(std::integral auto rhs) noexcept {
			return *this &= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator|(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			return xieite::big_int<UInt>::bit_op(lhs, rhs, std::bit_or());
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator|(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs | xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator|=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this | rhs;
		}

		constexpr xieite::big_int<UInt>& operator|=(std::integral auto rhs) noexcept {
			return *this |= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator^(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			return xieite::big_int<UInt>::bit_op(lhs, rhs, std::bit_xor());
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator^(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs ^ xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator^=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this ^ rhs;
		}

		constexpr xieite::big_int<UInt>& operator^=(std::integral auto rhs) noexcept {
			return *this ^= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator<<(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			if (!lhs || !rhs) {
				return lhs;
			}
			if (rhs.neg) {
				return lhs >> -rhs;
			}
			const std::size_t data_shift = static_cast<std::size_t>(rhs) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<UInt>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(rhs) & (xieite::bit_size<UInt> - 1);
			auto result_data = std::vector<UInt>(data_shift, 0);
			result_data.insert(result_data.end(), lhs.data.begin(), lhs.data.end());
			if (bits_shift) {
				UInt carry = 0;
				for (std::size_t i = 0; i < lhs.data.size(); ++i) {
					result_data[i + data_shift] = (lhs.data[i] << bits_shift) | carry;
					carry = lhs.data[i] >> (xieite::bit_size<UInt> - bits_shift);
				}
				if (carry) {
					result_data.push_back(carry);
				}
			}
			return xieite::big_int<UInt>(result_data, lhs.neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator<<(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs << xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator<<=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this << rhs;
		}

		constexpr xieite::big_int<UInt>& operator<<=(std::integral auto rhs) noexcept {
			return *this <<= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator>>(const xieite::big_int<UInt>& lhs, const xieite::big_int<UInt>& rhs) noexcept {
			if (!lhs || !rhs) {
				return lhs;
			}
			if (rhs.neg) {
				return lhs >> -rhs;
			}
			const std::size_t data_shift = static_cast<std::size_t>(rhs) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<UInt>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(rhs) & (xieite::bit_size<UInt> - 1);
			if (data_shift >= lhs.data.size()) {
				return 0;
			}
			auto result_data = std::vector<UInt>(std::ranges::next(lhs.data.begin(), static_cast<xieite::ssize_t>(data_shift), lhs.data.end()), lhs.data.end());
			if (bits_shift) {
				UInt carry = 0;
				for (UInt& limb : std::views::reverse(result_data)) {
					carry = std::exchange(limb, (limb >> bits_shift) | carry) << (xieite::bit_size<UInt> - bits_shift);
				}
			}
			return xieite::big_int<UInt>(result_data, lhs.neg) - lhs.neg;
		}

		[[nodiscard]] friend constexpr xieite::big_int<UInt> operator>>(const xieite::big_int<UInt>& lhs, std::integral auto rhs) noexcept {
			return lhs >> xieite::big_int<UInt>(rhs);
		}

		constexpr xieite::big_int<UInt>& operator>>=(const xieite::big_int<UInt>& rhs) noexcept {
			return *this = *this >> rhs;
		}

		constexpr xieite::big_int<UInt>& operator>>=(std::integral auto rhs) noexcept {
			return *this >>= xieite::big_int<UInt>(rhs);
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> abs() const noexcept {
			return xieite::big_int<UInt>(this->data);
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> pow(xieite::big_int<UInt> exp) const {
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
			xieite::big_int<UInt> base = *this;
			xieite::big_int<UInt> result = 1;
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

		[[nodiscard]] constexpr xieite::big_int<UInt> pow(std::integral auto exp) const {
			return this->pow(xieite::big_int<UInt>(exp));
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> root(const xieite::big_int<UInt>& deg) const {
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
			xieite::big_int<UInt> foo = deg - 1;
			xieite::big_int<UInt> bar = *this;
			xieite::big_int<UInt> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.pow(foo)) / deg;
			}
			return baz;
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> root(std::integral auto deg) const {
			return this->root(xieite::big_int<UInt>(deg));
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> log(const xieite::big_int<UInt>& base) const {
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

		[[nodiscard]] constexpr xieite::big_int<UInt> log(std::integral auto base) const {
			return this->log(xieite::big_int<UInt>(base));
		}

		[[nodiscard]] constexpr std::string str(xieite::ssize_t radix = 10, xieite::number_str_config config = {}) const noexcept {
			if (!*this || !radix) {
				return std::string(1, config.digits[0]);
			}
			std::string result;
			xieite::big_int<UInt> x = this->abs();
			if (radix == 1) {
				result = std::string(static_cast<std::size_t>(x), config.digits[1]);
			} else if (radix == -1) {
				result = config.digits[1];
				for (std::size_t length = static_cast<std::size_t>(x); --length;) {
					result += config.digits[0];
					result += config.digits[1];
				}
			} else {
				do {
					xieite::ssize_t idx = static_cast<xieite::ssize_t>(x % radix);
					x /= radix;
					if (idx < 0) {
						idx += radix;
						++x;
					}
					result.insert(0, 1, config.digits[static_cast<std::size_t>(idx) * (static_cast<std::size_t>(idx) < config.digits.size())]);
				} while (x);
			}
			if (*this < 0) {
				result.insert(0, 1, config.minus[0]);
			}
			return result;
		}

	private:
		std::vector<UInt> data;
		bool neg;

		[[nodiscard]] static constexpr xieite::big_int<UInt> bit_op(xieite::big_int<UInt> lhs, xieite::big_int<UInt> rhs, auto fn) noexcept {
			const bool l_neg = lhs.neg;
			const bool r_neg = rhs.neg;
			lhs += l_neg;
			rhs += r_neg;
			xieite::big_int<UInt> result;
			result.data.clear();
			result.neg = fn(l_neg, r_neg);
			for (std::size_t i = 0; (i < lhs.data.size()) || (i < rhs.data.size()); ++i) {
				const UInt limb = fn(
					(i < lhs.data.size())
						? (l_neg ? ~lhs.data[i] : lhs.data[i])
						: (std::numeric_limits<UInt>::max() * l_neg),
					(i < rhs.data.size())
						? (r_neg ? ~rhs.data[i] : rhs.data[i])
						: (std::numeric_limits<UInt>::max() * r_neg)
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
			const xieite::big_int<UInt> abs = this->abs();
			return abs && !(abs & (abs - 1));
		}

		[[nodiscard]] constexpr xieite::big_int<UInt> log2() const noexcept {
			return xieite::big_int<UInt>(xieite::bit_size<UInt>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}
	};
}

#endif
