#ifndef DETAIL_XTE_HEADER_MATH_BIG_INT
#	define DETAIL_XTE_HEADER_MATH_BIG_INT
#
#	include "../data/array.hpp"
#	include "../data/fixed_array.hpp"
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../data/range_cmp.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../data/uppercase.hpp"
#	include "../literal/radix.hpp"
#	include "../math/abs.hpp"
#	include "../math/add_checked.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/digits.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/is_single_bit.hpp"
#	include "../math/max.hpp"
#	include "../math/number.hpp"
#	include "../math/number_format_config.hpp"
#	include "../math/rshift.hpp"
#	include "../math/sub_checked.hpp"
#	include "../math/wide_uint.hpp"
#	include "../math/width.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_same.hpp"
#	include "../trait/is_unsigned.hpp"
#	include "../util/error.hpp"
#	include "../util/exchange.hpp"
#	include "../util/numbers.hpp"
#	include "../util/xvalue.hpp"
#	include <compare>
#	include <ranges>
#	include <type_traits>

namespace xte {
	struct big_int {
	private:
		xte::array<xte::umax> _data;
		bool _neg = false;

		constexpr void _normalize() {
			if (!this->_data.size()) {
				this->_data.push();
			}
			while ((this->_data.size() > 1) && !this->_data.back()) {
				this->_data.pop();
			}
			this->_neg &= !!*this;
		}

		[[nodiscard]] constexpr bool _is_single_bit() const {
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

		[[nodiscard]] constexpr std::strong_ordering _cmp(const xte::big_int& rhs) const {
			std::strong_ordering order = this->_data.size() <=> rhs._data.size();
			return std::is_eq(order) ? xte::range_cmp(std::views::reverse(this->_data), std::views::reverse(rhs._data)) : order;
		}

		[[nodiscard]] constexpr xte::big_int& _add(auto&& rhs) {
			if (!*this) {
				return *this = XTE_FWD(rhs);
			}
			if (this->_neg != rhs._neg) {
				return *this -= -XTE_FWD(rhs);
			}
			if (rhs) {
				this->_data.resize(xte::max(this->_data.size(), rhs._data.size()) + 1);
				xte::umax carry = 0;
				for (xte::uz i : std::views::indices(this->_data.size())) {
					xte::umax rhs_digit = 0;
					if (i < rhs._data.size()) {
						rhs_digit = rhs._data[i];
					} else if (!carry) {
						break;
					}
					this->_data[i] += rhs_digit + xte::exchange(carry, !xte::add_checked(this->_data[i], rhs_digit, carry));
				}
				this->_normalize();
			}
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int& _sub(auto&& rhs) {
			if (!*this) {
				return *this = -XTE_FWD(rhs);
			}
			if (this->_neg != rhs._neg) {
				return *this += -XTE_FWD(rhs);
			}
			if (this->_neg ? (*this > rhs) : (*this < rhs)) {
				return *this = -(XTE_FWD(rhs) - xte::xvalue(*this));
			}
			if (rhs) {
				xte::umax borrow = 0;
				for (xte::uz i : std::views::indices(this->_data.size())) {
					xte::umax rhs_digit = 0;
					if (i < rhs._data.size()) {
						rhs_digit = rhs._data[i];
					} else if (!borrow) {
						break;
					}
					this->_data[i] -= rhs_digit + xte::exchange(borrow, !xte::sub_checked(this->_data[i], rhs_digit, borrow));
				}
				this->_normalize();
			}
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int& _mul(auto&& rhs) {
			if (!*this || !rhs) {
				return *this = 0;
			}
			bool same_sign = this->_neg == rhs._neg;
			do {
				if (rhs._is_single_bit()) {
					this->_data.insert_count(0, rhs._data.size() - 1, 0);
					*this <<= xte::digits(rhs._data.back(), 2) - 1;
					break;
				}
				xte::big_int copy = XTE_FWD(rhs).abs();
				if (this->_is_single_bit()) {
					copy._data.insert_count(0, this->_data.size() - 1, 0);
					copy <<= xte::digits(this->_data.back(), 2) - 1;
					*this = xte::xvalue(copy);
					break;
				}
				if ((this->_data.size() < 2) && (copy._data.size() < 2)) {
					auto [lo, hi] = xte::wide_uint<xte::umax>(this->_data[0]) * copy._data[0];
					this->_data[0] = lo;
					if (hi) {
						this->_data.push(hi);
					}
					break;
				}
				this->_neg = false;
				xte::uz half_size = xte::max(this->_data.size(), copy._data.size()) / 2;
				auto lhs_hi = xte::big_int(std::from_range, this->_data.slice(half_size));
				this->_data.erase(half_size, -1uz);
				auto rhs_hi = xte::big_int(std::from_range, copy._data.slice(half_size));
				copy._data.erase(half_size, -1uz);
				xte::big_int prod0 = *this * copy;
				xte::big_int prod1 = lhs_hi * rhs_hi;
				xte::big_int prod2 = (*this + lhs_hi) * (copy + rhs_hi) - prod0 - prod1;
				*this = prod0 + (prod1 << (xte::width<xte::umax> * half_size * 2)) + (prod2 << (xte::width<xte::umax> * half_size));
			} while (false);
			this->_neg = !same_sign;
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int _div(const xte::big_int& rhs) {
			xte::big_int quot;
			quot._data.resize(this->_data.size());
			quot._neg = xte::exchange(this->_neg, false);
			while (true) {
				xte::big_int tmp = rhs.abs();
				if (*this < tmp) {
					break;
				}
				xte::uz lhs_last_bits = xte::digits(this->_data.back(), 2);
				xte::uz rhs_last_bits = xte::digits(rhs._data.back(), 2);
				xte::uz shift_digits = this->_data.size() - rhs._data.size() - (lhs_last_bits < rhs_last_bits);
				xte::uz shift_bits = (lhs_last_bits - rhs_last_bits + xte::width<xte::umax>) % xte::width<xte::umax>;
				tmp._data.insert_count(0, shift_digits, 0);
				tmp <<= shift_bits;
				if (*this < tmp) {
					tmp >>= 1;
					if (!shift_bits--) {
						shift_bits += xte::width<xte::umax>;
						--shift_digits;
					}
				}
				quot._data[shift_digits] |= static_cast<xte::umax>(1) << shift_bits;
				*this -= tmp;
			}
			this->_neg = quot._neg && *this;
			quot._neg ^= rhs._neg;
			quot._normalize();
			return quot;
		}

		[[nodiscard]] constexpr xte::big_int& _bitwise(const xte::big_int& rhs, auto func) {
			xte::umax lhs_neg = this->_neg;
			xte::umax rhs_neg = rhs._neg;
			xte::umax lhs_borrow = lhs_neg;
			xte::umax rhs_borrow = rhs_neg;
			this->_data.resize(xte::max(this->_data.size(), rhs._data.size()));
			xte::umax lhs_carry = this->_neg = func(lhs_neg, rhs_neg);
			for (xte::uz i : std::views::indices(this->_data.size())) {
				xte::umax rhs_digit = (i < rhs._data.size()) ? rhs._data[i] : 0;
				lhs_carry &= !(this->_data[i] = (func((this->_data[i] - xte::exchange(lhs_borrow, this->_data[i] < lhs_borrow)) ^ -lhs_neg, (rhs_digit - xte::exchange(rhs_borrow, rhs_digit < rhs_borrow)) ^ -rhs_neg) ^ -this->_neg) + lhs_carry);
			}
			this->_normalize();
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int& _lshift(const xte::big_int& rhs) {
			if (*this && rhs) {
				xte::uz shift_digits = 0;
				for (xte::uz i = 0; (i < rhs._data.size()) && (i <= (xte::width<xte::uz> / xte::width<xte::umax>)); ++i) {
					shift_digits |= xte::lshift(static_cast<xte::uz>(rhs._data[i]), i * xte::width<xte::umax>) / xte::width<xte::umax>;
				}
				xte::uz shift_bits = rhs._data[0] % xte::width<xte::umax>;
				this->_data.reserve(shift_digits + !!shift_bits);
				this->_data.insert_count(0, shift_digits, 0);
				if (shift_bits) {
					xte::umax carry = 0;
					for (xte::umax& digit : this->_data | std::views::drop(shift_digits)) {
						carry = xte::exchange(digit, (digit << shift_bits) | carry) >> (xte::width<xte::umax> - shift_bits);
					}
					if (carry) {
						this->_data.push(carry);
					}
					this->_normalize();
				}
			}
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int& _rshift(const xte::big_int& rhs) {
			if (*this && rhs) {
				xte::uz shift_digits = 0;
				for (xte::uz i = 0; (i < rhs._data.size()) && (i <= (xte::width<xte::uz> / xte::width<xte::umax>)); ++i) {
					shift_digits |= xte::lshift(static_cast<xte::uz>(rhs._data[i]), i * xte::width<xte::umax>) / xte::width<xte::umax>;
				}
				if (shift_digits >= this->_data.size()) {
					return *this = 0;
				}
				this->_data.erase(0, shift_digits);
				if (xte::uz shift_bits = rhs._data[0] % xte::width<xte::umax>) {
					xte::umax carry = 0;
					for (xte::umax& digit : std::views::reverse(this->_data)) {
						carry = xte::exchange(digit, (digit >> shift_bits) | carry) << (xte::width<xte::umax> - shift_bits);
					}
					if (carry) {
						*this -= +this->_neg;
					}
				}
				this->_normalize();
			}
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int _pow(this auto&& base, auto&& exp) {
			if ((base == 1) || (base == -1) || (exp == 1)) {
				return (base._neg && !(exp._data[0] & 1)) ? -XTE_FWD(base) : XTE_FWD(base);
			}
			if (exp < 0) {
				if (!base) {
					throw xte::error("power of zero to negative exponent");
				}
				return 0;
			}
			if (!exp) {
				return 1;
			}
			if (!base) {
				return XTE_FWD(base);
			}
			return ([base = XTE_FWD(base), exp = XTE_FWD(exp)] mutable {
				xte::big_int power = 1;
				while (exp > 1) {
					if (exp._data[0] & 1) {
						power *= base;
						--exp;
					}
					base *= base;
					exp >>= 1;
				}
				power *= base;
				return power;
			})();
		}

	public:
		template<xte::is_arithmetic T = xte::umax>
		[[nodiscard]] explicit(!xte::is_int<T>)
		constexpr big_int(T x = 0) noexcept(false)
		: _neg(x < 0) {
			if (!xte::is_finite(x)) {
				throw xte::error("value is not finite");
			}
			auto abs = xte::number(xte::abs(x));
			do {
				this->_data.push(static_cast<xte::umax>(abs));
			} while (abs >>= xte::width<xte::umax>);
		}

		[[nodiscard]] explicit(false) constexpr big_int(const xte::big_int&) noexcept(false) = default;

		[[nodiscard]] explicit(false) constexpr big_int(xte::big_int&&) noexcept = default;

		template<typename Range = xte::array<xte::umax>>
		[[nodiscard]] constexpr big_int(std::from_range_t, Range&& range, bool neg = false) XTE_ARROW_CTOR(
			this->_normalize(),
			_data,((std::from_range, XTE_FWD(range))),
			_neg,((neg))
		)

		template<xte::is_int Radix = xte::uz>
		[[nodiscard]] explicit constexpr big_int(xte::string_view string, Radix radix = 10, const xte::number_format_config& config = {}) noexcept(false)
		: xte::big_int(xte::big_int::parse(string, radix, config)) {}

		constexpr xte::big_int& operator=(const xte::big_int&) & noexcept(false) = default;

		constexpr xte::big_int& operator=(xte::big_int&&) & noexcept = default;

		template<xte::is_arithmetic T>
		[[nodiscard]] explicit constexpr operator T() const noexcept {
			xte::number<T> result;
			xte::uz shift = 0;
			for (xte::umax digit : this->_data) {
				result += xte::number<T>(digit) << shift;
				shift += xte::width<xte::umax>;
				if constexpr (xte::is_int<T>) {
					if (shift >= xte::width<T>) {
						break;
					}
				}
			}
			return this->_neg ? -result : result;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return (this->_data.size() > 1) || this->_data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xte::big_int& lhs, const xte::big_int& rhs) noexcept {
			std::strong_ordering order = rhs._neg <=> lhs._neg;
			return std::is_eq(order) ? (lhs._neg ? rhs._cmp(lhs) : lhs._cmp(rhs)) : order;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xte::big_int& lhs, xte::is_int auto rhs) noexcept {
			std::strong_ordering order = (rhs < 0) <=> lhs._neg;
			if (!std::is_eq(order)) {
				return order;
			}
			if (lhs._data.size() > xte::max(1, xte::width<decltype(rhs)> / xte::width<xte::umax>)) {
				return false <=> lhs._neg;
			}
			auto rhs_abs = xte::abs(rhs);
			using unsigned_type = std::common_type_t<xte::umax, decltype(rhs_abs)>;
			auto lhs_abs = lhs._neg ? -static_cast<unsigned_type>(lhs) : static_cast<unsigned_type>(lhs);
			return lhs._neg ? (rhs_abs <=> lhs_abs) : (lhs_abs <=> rhs_abs);
		}

		[[nodiscard]] friend constexpr std::partial_ordering operator<=>(const xte::big_int& lhs, xte::is_float auto rhs) noexcept {
			return static_cast<decltype(rhs)>(lhs) <=> rhs;
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::big_int&, const xte::big_int&) noexcept = default;

		[[nodiscard]] friend constexpr bool operator==(const xte::big_int& lhs, xte::is_int auto rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::big_int& lhs, xte::is_float auto rhs) noexcept {
			return xte::approx_equal(static_cast<decltype(rhs)>(lhs), rhs);
		}

		[[nodiscard]] constexpr auto&& operator+(this auto&& self) noexcept {
			return XTE_FWD(self);
		}

		[[nodiscard]] friend constexpr xte::big_int operator+(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs += rhs);
		}

		[[nodiscard]] friend constexpr xte::big_int operator+(xte::big_int lhs, xte::big_int&& rhs) noexcept(false) {
			return xte::xvalue(lhs += xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator+=(const xte::big_int& rhs) & noexcept(false) {
			return this->_add(rhs);
		}

		constexpr xte::big_int& operator+=(xte::big_int&& rhs) & noexcept(false) {
			return this->_add(xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator++() & noexcept(false) {
			return *this += 1;
		}

		constexpr xte::big_int operator++(int) & noexcept(false) {
			return xte::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xte::big_int operator-() const & noexcept(false) {
			return xte::big_int(std::from_range, this->_data, !this->_neg);
		}

		[[nodiscard]] constexpr xte::big_int operator-() && noexcept {
			this->_neg ^= !!*this;
			return xte::xvalue(*this);
		}

		[[nodiscard]] friend constexpr xte::big_int operator-(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return lhs -= rhs;
		}

		[[nodiscard]] friend constexpr xte::big_int operator-(xte::big_int lhs, xte::big_int&& rhs) noexcept(false) {
			return lhs -= xte::xvalue(rhs);
		}

		constexpr xte::big_int& operator-=(const xte::big_int& rhs) & noexcept(false) {
			return this->_sub(rhs);
		}

		constexpr xte::big_int& operator-=(xte::big_int&& rhs) & noexcept(false) {
			return this->_sub(xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator--() & noexcept(false) {
			return *this -= 1;
		}

		constexpr xte::big_int operator--(int) & noexcept(false) {
			return xte::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xte::big_int operator*(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs *= rhs);
		}

		[[nodiscard]] friend constexpr xte::big_int operator*(xte::big_int lhs, xte::big_int&& rhs) noexcept(false) {
			return xte::xvalue(lhs *= xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator*=(const xte::big_int& rhs) & noexcept(false) {
			return this->_mul(rhs);
		}

		constexpr xte::big_int& operator*=(xte::big_int&& rhs) & noexcept(false) {
			return this->_mul(xte::xvalue(rhs));
		}

		[[nodiscard]] friend constexpr xte::big_int operator/(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs /= rhs);
		}

		constexpr xte::big_int& operator/=(const xte::big_int& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::error("division by zero");
			}
			if ((this->_data.size() < 3) && (rhs._data.size() < 3)) {
				auto [lo, hi] = xte::wide_uint<xte::umax>(this->_data[0], (this->_data.size() > 1) ? this->_data[1] : 0) / xte::wide_uint<xte::umax>(rhs._data[0], (rhs._data.size() > 1) ? rhs._data[1] : 0);
				this->_data.resize(1 + !!hi);
				this->_data[0] = lo;
				if (hi) {
					this->_data[1] = hi;
				}
			} else {
				if (!rhs._is_single_bit()) {
					return *this = this->_div(rhs);
				}
				this->_data.erase(0, rhs._data.size() - 1);
				*this >>= xte::digits(rhs._data.back(), 2) - 1;
			}
			this->_neg ^= rhs._neg;
			this->_normalize();
			return *this;
		}

		[[nodiscard]] friend constexpr xte::big_int operator%(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs %= rhs);
		}

		constexpr xte::big_int& operator%=(const xte::big_int& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::error("remainder of division by zero");
			}
			if (!*this || (this->_data == rhs._data)) {
				return *this = 0;
			}
			if (rhs._is_single_bit()) {
				this->_data.resize(rhs._data.size());
				this->_data.back() &= rhs._data.back() - 1;
				this->_normalize();
				return *this;
			}
			(void)this->_div(rhs);
			return *this;
		}

		[[nodiscard]] constexpr xte::big_int operator~(this auto&& self) noexcept(false) {
			return -XTE_FWD(self) - 1;
		}

		[[nodiscard]] friend constexpr xte::big_int operator&(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs &= xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator&=(const xte::big_int& rhs) & noexcept(false) {
			return this->_bitwise(xte::xvalue(rhs), XTE_LIFT_INFIX(&));
		}

		[[nodiscard]] friend constexpr xte::big_int operator|(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs |= xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator|=(const xte::big_int& rhs) & noexcept(false) {
			return this->_bitwise(xte::xvalue(rhs), XTE_LIFT_INFIX(|));
		}

		[[nodiscard]] friend constexpr xte::big_int operator^(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs ^= xte::xvalue(rhs));
		}

		constexpr xte::big_int& operator^=(const xte::big_int& rhs) & noexcept(false) {
			return this->_bitwise(xte::xvalue(rhs), XTE_LIFT_INFIX(^));
		}

		[[nodiscard]] friend constexpr xte::big_int operator<<(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs <<= rhs);
		}

		constexpr xte::big_int& operator<<=(const xte::big_int& rhs) & noexcept(false) {
			return rhs._neg ? this->_rshift(rhs) : this->_lshift(rhs);
		}

		[[nodiscard]] friend constexpr xte::big_int operator>>(xte::big_int lhs, const xte::big_int& rhs) noexcept(false) {
			return xte::xvalue(lhs >>= rhs);
		}

		constexpr xte::big_int& operator>>=(const xte::big_int& rhs) & noexcept(false) {
			return rhs._neg ? this->_lshift(rhs) : this->_rshift(rhs);
		}

		[[nodiscard]] constexpr xte::big_int abs() const & noexcept(false) {
			return xte::big_int(std::from_range, this->_data);
		}

		[[nodiscard]] constexpr xte::big_int abs() && noexcept {
			this->_neg = false;
			return xte::xvalue(*this);
		}

		[[nodiscard]] constexpr xte::big_int pow(this auto&& base, const xte::big_int& exp) noexcept(false) {
			return XTE_FWD(base)._pow(exp);
		}

		[[nodiscard]] constexpr xte::big_int pow(this auto&& base, xte::big_int&& exp) noexcept(false) {
			return XTE_FWD(base)._pow(xte::xvalue(exp));
		}

		[[nodiscard]] constexpr xte::big_int root(const xte::big_int& degree) const noexcept(false) {
			if (this->_neg) {
				throw xte::error("root of negative radicand");
			}
			if (!degree) {
				throw xte::error("root of zeroth degree");
			}
			if (*this == 1) {
				return *this;
			}
			if (!*this || degree._neg) {
				return 0;
			}
			xte::big_int tmp = *this;
			xte::big_int exp = degree - 1;
			xte::big_int root = tmp + 1;
			while (tmp < root) {
				root = tmp;
				xte::big_int quot = *this / tmp.pow(exp);
				((tmp *= exp) += xte::xvalue(quot)) /= degree;
			}
			return root;
		}

		[[nodiscard]] constexpr xte::big_int log(const xte::big_int& base) const noexcept(false) {
			if (!base) {
				return 0;
			}
			if (this->_neg) {
				throw xte::error("logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw xte::error("logarithm to unary base");
			}
			if (base._neg) {
				throw xte::error("logarithm to negative base");
			}
			if (auto cmp = *this <=> base; std::is_lteq(cmp)) {
				return +std::is_eq(cmp);
			}
			xte::uz log = (xte::digits(this->_data.back(), 2) - 1) / (xte::digits(base._data.back(), 2) - 1);
			return ((base._data.size() > 1) ? (log + (this->_data.size() - 1) / (base._data.size() - 1)) : log) - (*this < base.pow(log));
		}

		static constexpr struct parse {
			template<xte::is_int Radix = xte::uz>
			[[nodiscard]] static constexpr xte::big_int operator()(xte::string_view string, Radix radix = 10, const xte::number_format_config& config = {}) noexcept(false) {
				return xte::big_int::parse::with_index(string, radix, config).value;
			}

			template<xte::is_int Radix = xte::uz>
			[[nodiscard]] static constexpr auto with_index(xte::string_view string, Radix radix = 10, const xte::number_format_config& config = {}) noexcept(false) {
				struct { xte::big_int value = 0; xte::uz index = 0; } result;
				xte::string_view digits = config.digits.slice(0, xte::max(2, static_cast<xte::uz>(xte::abs(radix))));
				bool neg = config.minus.contains(string[0]);
				for (xte::uz i = neg || config.plus.contains(string[0]); i < string.size(); result.index = ++i) {
					if (xte::uz digit = digits.find(string[i]); ~digit) {
						(result.value *= radix) += digit;
						continue;
					}
					break;
				}
				result.value._neg = neg && result.value;
				return result;
			}
		} parse {};

		template<xte::is_int Radix = xte::uz>
		[[nodiscard]] constexpr xte::string str(this auto&& self, Radix radix = 10, const xte::number_format_config& config = {}) noexcept(false) {
			if (!self || !radix) {
				return { config.digits[0] };
			}
			xte::string result;
			bool neg = self._neg;
			xte::big_int abs = XTE_FWD(self).abs();
			do {
				if (radix == 1) {
					result += xte::string(static_cast<xte::uz>(abs), config.digits[1]);
					break;
				}
				if constexpr (xte::is_signed<decltype(radix)>) {
					if (radix == -1) {
						result += config.digits[1];
						for (xte::uz i = static_cast<xte::uz>(abs - 1); i--;) {
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
			if (neg) {
				result += config.minus[0];
			}
			std::ranges::reverse(result);
			return result;
		}
	};
}

namespace xte::literal::big_int {
	template<char... digits>
	[[nodiscard]] constexpr xte::big_int operator""_big() noexcept(false) {
		static constexpr xte::uz radix = xte::literal::radix::operator""_radix<digits...>();
		xte::big_int result;
		for (char digit : xte::fixed_array { digits... } | std::views::drop(2 * ((radix == 16) || (radix == 2)))) {
			if (digit == '\'') {
				continue;
			}
			xte::uz index = xte::string_view("0123456789ABCDEF").slice(0, radix).find(xte::uppercase(digit));
			if (!~index) {
				throw xte::error("digit outside radix");
			}
			(result *= radix) += index;
		}
		return result;
	}
}

template<>
struct std::formatter<xte::big_int> {
	constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	auto format(const xte::big_int& x, std::format_context& ctx) const noexcept(false) {
		return std::format_to(ctx.out(), "{}", x.str());
	}
};

#endif
