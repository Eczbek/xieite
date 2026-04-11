#ifndef DETAIL_XTE_HEADER_MATH_BIG_INT
#	define DETAIL_XTE_HEADER_MATH_BIG_INT
#
#	include "../data/array.hpp"
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../data/range_cmp.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../func/gen.hpp"
#	include "../math/abs.hpp"
#	include "../math/add_checked.hpp"
#	include "../math/digits.hpp"
#	include "../math/is_single_bit.hpp"
#	include "../math/max.hpp"
#	include "../math/number_format_config.hpp"
#	include "../math/rshift.hpp"
#	include "../math/sub_checked.hpp"
#	include "../math/wide_uint.hpp"
#	include "../math/width.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_same.hpp"
#	include "../trait/is_unsigned.hpp"
#	include "../util/error.hpp"
#	include "../util/exchange.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <compare>
#	include <functional>
#	include <ranges>

namespace xte {
	template<xte::is_unsigned T = xte::uz>
	struct big_int {
		template<xte::is_unsigned>
		friend struct xte::big_int;

	private:
		xte::array<T> _data;
		bool _neg = false;

		constexpr void _normalize() noexcept(false) {
			if (!this->_data.size()) {
				this->_data.push(0);
			} else while ((this->_data.size() > 1) && !this->_data.back()) {
				this->_data.pop();
			}
			this->_neg &= !!*this;
		}

		[[nodiscard]] constexpr bool _is_single_bit() const noexcept {
			if (!xte::is_single_bit(this->_data.back())) {
				return false;
			}
			for (xte::uz i = 0; (i + 1) < this->_data.size(); ++i) {
				if (this->_data[i]) {
					return false;
				}
			}
			return true;
		}

		[[nodiscard]] constexpr xte::uz _log2() const noexcept {
			return xte::width<T> * ~-this->_data.size() + ~-xte::digits(this->_data.back(), 2);
		}

		constexpr auto _divide(const xte::big_int<T>& rhs) noexcept(false) {
			bool neg = xte::exchange(this->_neg, false);
			xte::big_int<T> quot;
			quot._data.resize(this->_log2() / xte::width<T> + 1);
			while (true) {
				xte::big_int<T> rhs_abs = rhs.abs();
				if (*this < rhs_abs) {
					break;
				}
				xte::uz shift = this->_log2() - rhs_abs._log2();
				rhs_abs <<= shift;
				if (rhs_abs > *this) {
					rhs_abs >>= 1;
					--shift;
				}
				quot._data[shift / xte::width<T>] |= static_cast<T>(1) << (shift % xte::width<T>);
				*this -= rhs_abs;
			}
			this->_neg = neg;
			quot._normalize();
			return quot;
		}

		[[nodiscard]] constexpr xte::big_int<T>& _bitwise(xte::big_int<T> rhs, auto func) noexcept(false) {
			T lhs_neg = this->_neg;
			T rhs_neg = rhs._neg;
			*this += lhs_neg;
			rhs += rhs_neg;
			xte::uz size = xte::max(this->_data.size(), rhs._data.size());
			this->_data.resize(size);
			rhs._data.resize(size);
			this->_neg = func(lhs_neg, rhs_neg);
			for (xte::uz i : std::views::indices(size)) {
				this->_data[i] = func(this->_data[i] ^ -lhs_neg, rhs._data[i] ^ -rhs_neg) ^ -this->_neg;
			}
			return *this -= +this->_neg;
		}

	public:
		using type = T;

		template<xte::is_int U = T>
		[[nodiscard]] explicit(false) constexpr big_int(U x = 0) noexcept(false)
		: _neg(x < 0) {
			auto abs = xte::abs(x);
			do {
				this->_data.push(static_cast<T>(abs));
			} while ((abs = xte::rshift(abs, xte::width<T>)));
		}

		[[nodiscard]] explicit(false) constexpr big_int(const xte::big_int<T>&) noexcept(false) = default;

		[[nodiscard]] explicit(false) constexpr big_int(xte::big_int<T>&&) noexcept = default;

		template<typename U>
		requires(!xte::is_same<T, U>)
		[[nodiscard]] explicit constexpr big_int(const xte::big_int<U>& other) noexcept(false)
		: _neg(other._neg) {
			if constexpr (xte::width<T> >= xte::width<U>) {
				xte::uz shift = xte::width<T>;
				for (U digit : other._data) {
					if ((shift += xte::width<U>) >= xte::width<T>) {
						this->_data.push((shift = 0));
					}
					this->_data.back() |= digit << shift;
				}
			} else {
				for (U digit : other._data) {
					xte::uz shift = 0;
					do {
						this->_data.push(static_cast<T>(digit >> shift));
					} while ((shift += xte::width<T>) < xte::width<U>);
				}
				this->_normalize();
			}
		}

		template<typename Range = xte::array<T>>
		[[nodiscard]] constexpr big_int(std::from_range_t, Range&& range, bool neg = false) XTE_ARROW_CTOR(
			this->_normalize(),
			_data,((std::from_range, XTE_FWD(range))),
			_neg,((neg))
		)

		template<xte::is_int Radix = xte::uz>
		[[nodiscard]] explicit constexpr big_int(xte::string_view string, Radix radix = 10uz, const xte::number_format_config& config = {}) noexcept(false)
		: xte::big_int<T>(0) {
			bool neg = config.minus.contains(string[0]);
			for (char c : string | std::views::drop(neg || config.plus.contains(string[0]))) {
				xte::uz digit = config.digits.find(c);
				if (!~digit) {
					break;
				}
				(*this *= radix) += digit;
			}
			this->_neg = neg;
		}

		constexpr xte::big_int<T>& operator=(const xte::big_int<T>&) noexcept(false) = default;

		constexpr xte::big_int<T>& operator=(xte::big_int<T>&&) noexcept = default;

		template<xte::is_int U>
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			U result = 0;
			xte::uz shift = 0;
			for (T digit : this->_data) {
				result |= static_cast<U>(xte::lshift(digit, shift));
				if ((shift += xte::width<T>) >= xte::width<U>) {
					break;
				}
			}
			return this->_neg ? -result : result;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return (this->_data.size() > 1) || this->_data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xte::big_int<T>& lhs, const xte::big_int<T>& rhs) noexcept {
			std::strong_ordering order = rhs._neg <=> lhs._neg;
			if (std::is_eq(order)) {
				if (lhs._neg) {
					if (std::is_eq((order = rhs._data.size() <=> lhs._data.size()))) {
						return xte::range_cmp(std::views::reverse(rhs._data), std::views::reverse(lhs._data));
					}
				} else if (std::is_eq((order = lhs._data.size() <=> rhs._data.size()))) {
					return xte::range_cmp(std::views::reverse(lhs._data), std::views::reverse(rhs._data));
				}
			}
			return order;
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::big_int<T>&, const xte::big_int<T>&) noexcept = default;

		[[nodiscard]] constexpr xte::big_int<T> operator+() const noexcept(false) {
			return *this;
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator+(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs += rhs;
		}

		constexpr xte::big_int<T>& operator+=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!*this) {
				return *this = rhs;
			}
			if (!rhs) {
				return *this;
			}
			if (this->_neg != rhs._neg) {
				return *this -= -rhs;
			}
			xte::array<T> sum_data;
			T carry = 0;
			for (xte::uz i = 0; carry || (i < this->_data.size()) || (i < rhs._data.size()); ++i) {
				T lhs_digit = (i < this->_data.size()) ? this->_data[i] : 0;
				T rhs_digit = (i < rhs._data.size()) ? rhs._data[i] : 0;
				sum_data.push(lhs_digit + rhs_digit + carry);
				carry = !xte::add_checked(lhs_digit, rhs_digit, carry);
			}
			this->_data = xte::xvalue(sum_data);
			return *this;
		}

		constexpr xte::big_int<T>& operator++() noexcept(false) {
			return *this += 1;
		}

		constexpr xte::big_int<T> operator++(int) noexcept(false) {
			return xte::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xte::big_int<T> operator-() const noexcept(false) {
			return xte::big_int<T>(std::from_range, this->_data, !this->_neg);
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator-(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs -= rhs;
		}

		constexpr xte::big_int<T>& operator-=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!*this) {
				return *this = -rhs;
			}
			if (!rhs) {
				return *this;
			}
			if (this->_neg != rhs._neg) {
				return *this += -rhs;
			}
			if (this->_neg ? (*this > rhs) : (*this < rhs)) {
				return *this = -(rhs - *this);
			}
			if (*this == rhs) {
				return *this = 0;
			}
			xte::array<T> diff_data;
			T borrow = 0;
			for (xte::uz i = 0; borrow || (i < this->_data.size()); ++i) {
				T rhs_digit = (i < rhs._data.size()) ? rhs._data[i] : 0;
				diff_data.push(this->_data[i] - rhs_digit - borrow);
				borrow = (i < ~-this->_data.size()) && !xte::sub_checked(this->_data[i], rhs_digit, borrow);
			}
			this->_data = xte::xvalue(diff_data);
			this->_normalize();
			return *this;
		}

		constexpr xte::big_int<T>& operator--() noexcept(false) {
			return *this -= 1;
		}

		constexpr xte::big_int<T> operator--(int) noexcept(false) {
			return xte::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator*(xte::big_int<T> lhs, const xte::big_int<T> rhs) noexcept(false) {
			return lhs *= rhs;
		}

		constexpr xte::big_int<T>& operator*=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!*this || !rhs) {
				return *this = 0;
			}
			bool same_sign = this->_neg == rhs._neg;
			if ((*this == 1) || (*this == -1)) {
				return *this = (same_sign ? rhs : -rhs);
			}
			if ((rhs == 1) || (rhs == -1)) {
				return *this = (same_sign ? *this : -*this);
			}
			if (this->_is_single_bit()) {
				return *this = (same_sign ? (rhs.abs() << this->_log2()) : -(rhs.abs() << this->_log2()));
			}
			if (rhs._is_single_bit()) {
				return *this = (same_sign ? (this->abs() << rhs._log2()) : -(this->abs() << rhs._log2()));
			}
			if ((this->_data.size() < 2) && (rhs._data.size() < 2)) {
				auto [lo, hi] = xte::wide_uint<T>(this->_data[0]) * rhs._data[0];
				this->_data[0] = lo;
				if (hi) {
					this->_data.push(hi);
				}
			} else {
				xte::uz half_size = xte::max(this->_data.size(), rhs._data.size()) / 2;
				auto lhs_lo = xte::big_int<T>(std::from_range, this->_data.slice(0, half_size));
				auto lhs_hi = xte::big_int<T>(std::from_range, this->_data.slice(half_size));
				auto rhs_lo = xte::big_int<T>(std::from_range, rhs._data.slice(0, half_size));
				auto rhs_hi = xte::big_int<T>(std::from_range, rhs._data.slice(half_size));
				xte::big_int<T> prod0 = lhs_lo * rhs_lo;
				xte::big_int<T> prod1 = lhs_hi * rhs_hi;
				xte::big_int<T> prod2 = (lhs_lo + lhs_hi) * (rhs_lo + rhs_hi) - prod0 - prod1;
				*this = prod0 + (prod1 << (xte::width<T> * half_size * 2)) + (prod2 << (xte::width<T> * half_size));
			}
			this->_neg = !same_sign;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator/(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs /= rhs;
		}

		constexpr xte::big_int<T>& operator/=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!rhs) {
				throw xte::error("must not divide by zero");
			}
			if ((this->_data.size() < 2) && (rhs._data.size() < 2)) {
				this->_data[0] /= rhs._data[0];
			} else {
				if (!rhs._is_single_bit()) {
					return *this = this->_divide(rhs);
				}
				*this >>= rhs._log2();
			}
			this->_neg ^= rhs._neg;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator%(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs %= rhs;
		}

		constexpr xte::big_int<T>& operator%=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!rhs) {
				throw xte::error("must not take remainder of division by zero");
			}
			if (!*this || (this->_data == rhs._data)) {
				return *this = 0;
			}
			if (rhs._is_single_bit()) {
				return *this &= (rhs.abs() - 1);
			}
			this->_divide(rhs);
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int<T> operator~() const noexcept(false) {
			return -*this - 1;
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator&(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs &= rhs;
		}

		constexpr xte::big_int<T>& operator&=(const xte::big_int<T>& rhs) noexcept(false) {
			return this->_bitwise(rhs, std::bit_and<T>());
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator|(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs |= rhs;
		}

		constexpr xte::big_int<T>& operator|=(const xte::big_int<T>& rhs) noexcept(false) {
			return this->_bitwise(rhs, std::bit_or<T>());
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator^(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs ^= rhs;
		}

		constexpr xte::big_int<T>& operator^=(const xte::big_int<T>& rhs) noexcept(false) {
			return this->_bitwise(rhs, std::bit_xor<T>());
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator<<(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs <<= rhs;
		}

		constexpr xte::big_int<T>& operator<<=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!*this || !rhs) {
				return *this;
			}
			if (rhs._neg) {
				return *this >>= -rhs;
			}
			if (xte::uz bit_shift = static_cast<xte::uz>(rhs) & ~-xte::width<T>) {
				T carry = 0;
				for (T& digit : this->_data) {
					carry = xte::exchange(digit, (digit << bit_shift) | carry) >> (xte::width<T> - bit_shift);
				}
				if (carry) {
					this->_data.push(carry);
				}
			}
			this->_data.insert_range(0, xte::gen([digit_shift = static_cast<xte::uz>(rhs) / xte::width<T>] mutable {
				return digit_shift-- ? xte::opt<T>(0) : xte::null;
			}));
			return *this;
		}

		[[nodiscard]] friend constexpr xte::big_int<T> operator>>(xte::big_int<T> lhs, const xte::big_int<T>& rhs) noexcept(false) {
			return lhs >>= rhs;
		}

		constexpr xte::big_int<T>& operator>>=(const xte::big_int<T>& rhs) noexcept(false) {
			if (!*this || !rhs) {
				return *this;
			}
			if (rhs._neg) {
				return *this <<= -rhs;
			}
			xte::uz digit_shift = static_cast<xte::uz>(rhs) / xte::width<T>;
			if (digit_shift >= this->_data.size()) {
				return *this = 0;
			}
			this->_data.erase(0, digit_shift);
			if (xte::uz bit_shift = static_cast<xte::uz>(rhs) & ~-xte::width<T>) {
				T carry = 0;
				for (T& digit : std::views::reverse(this->_data)) {
					carry = xte::exchange(digit, (digit >> bit_shift) | carry) << (xte::width<T> - bit_shift);
				}
			}
			return *this -= +this->_neg;
		}

		[[nodiscard]] constexpr xte::big_int<T> abs() const noexcept(false) {
			return xte::big_int<T>(std::from_range, this->_data);
		}

		[[nodiscard]] constexpr xte::big_int<T> pow(const xte::big_int<T>& exp) const noexcept(false) {
			if ((*this == 1) || (exp == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * ((exp & 1) ? 1 : -1);
			}
			if (!*this || !exp) {
				if (exp._neg) {
					throw xte::error("must not take power of zero to negative exponent");
				}
				return +!exp;
			}
			return ([&, exp = exp] mutable {
				xte::big_int<T> base = *this;
				xte::big_int<T> power = 1;
				while (exp > 1) {
					if (exp._data[0] & 1) {
						power *= base;
						--exp;
					}
					base *= base;
					exp >>= 1;
				}
				return power * base;
			})();
		}

		[[nodiscard]] constexpr xte::big_int<T> root(const xte::big_int<T>& degree) const noexcept(false) {
			if (this->_neg) {
				throw xte::error("must not take root of negative radicand");
			}
			if (!degree) {
				throw xte::error("must not take root of zeroth degree");
			}
			if (*this == 1) {
				return *this;
			}
			if (degree._neg) {
				return 0;
			}
			xte::big_int<T> tmp = *this;
			xte::big_int<T> exp = degree - 1;
			xte::big_int<T> root = tmp + 1;
			while (tmp < root) {
				root = tmp;
				(tmp = tmp * exp += *this / tmp.pow(exp)) /= degree;
			}
			return root;
		}

		[[nodiscard]] constexpr xte::big_int<T> log(const xte::big_int<T>& base) const noexcept(false) {
			if (!base) {
				return 0;
			}
			if (this->_neg) {
				throw xte::error("must not take logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw xte::error("must not take logarithm to unary base");
			}
			if (base._neg) {
				throw xte::error("must not take logarithm to negative base");
			}
			return this->_log2() / base._log2();
		}

		template<xte::is_int Radix = xte::uz>
		[[nodiscard]] constexpr xte::string str(Radix radix = 10uz, const xte::number_format_config& config = {}) const noexcept(false) {
			if (!*this || !radix) {
				return { config.digits[0] };
			}
			xte::string result;
			xte::big_int<T> abs = this->abs();
			do {
				if (radix == 1) {
					result += xte::string(static_cast<xte::uz>(abs), config.digits[1]);
					break;
				}
				if constexpr (xte::is_signed<decltype(radix)>) {
					if (radix == -1) {
						result += config.digits[1];
						for (xte::uz i : std::views::indices(static_cast<xte::uz>(abs - 1))) {
							result += config.digits[0];
							result += config.digits[1];
						}
						break;
					}
				}
				do {
					auto rem = abs % radix;
					abs /= radix;
					if (rem < 0) {
						rem -= radix;
						++abs;
					}
					result += config.digits[static_cast<xte::uz>(rem)];
				} while (abs);
			} while (false);
			if (this->_neg) {
				result += config.minus[0];
			}
			std::ranges::reverse(result);
			return result;
		}
	};
}

namespace xte::literal::big_int {
	template<char... digits>
	[[nodiscard]] constexpr xte::big_int<> operator""_big() noexcept(false) {
		xte::string string = { digits... };
		if constexpr (sizeof...(digits) > 2) {
			switch (digits...[1]) {
				case 'X': case 'x':
					return xte::big_int(string.slice(2), 16);
				case 'B': case 'b':
					return xte::big_int(string.slice(2), 2);
			}
		}
		return xte::big_int(string);
	}
}

template<typename T>
struct std::formatter<xte::big_int<T>> {
	constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	auto format(const xte::big_int<T>& x, std::format_context& ctx) const noexcept(false) {
		return std::format_to(ctx.out(), "{}", x.str());
	}
};

#endif
