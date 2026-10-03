#ifndef DETAIL_XTE_HEADER_MATH_WIDE_INT
#	define DETAIL_XTE_HEADER_MATH_WIDE_INT
#
#	include "../aliases.hpp"
#	include "../class_traits.hpp"
#	include "../compare.hpp"
#	include "../detect/feature.hpp"
#	include "../exchange.hpp"
#	include "../fixed_array.hpp"
#	include "../fundamental_traits.hpp"
#	include "../lettercase.hpp"
#	include "../limits.hpp"
#	include "../literal/radix.hpp"
#	include "../macros.hpp"
#	include "../math/digits.hpp"
#	include "../math/bitwise.hpp"
#	include "../qual_traits.hpp"
#	include "../static_error.hpp"
#	include "../string.hpp"
#	include "../string_view.hpp"
#	include "../visitor.hpp"
#	include <algorithm>
#	include <compare>
#	include <ranges>

namespace DETAIL_XTE::wide_int {
	struct base {};

	template<typename half_type>
	constexpr xte::uz width = xte::width<half_type>;

	template<xte::is_privately_derived_from<base> half_type>
	constexpr xte::uz width<half_type> = DETAIL_XTE::wide_int::width<typename half_type::value_type>;

	inline constexpr auto rshift = xte::visitor {
		XTE_LIFT(xte::rshift),
		[]<xte::is_privately_derived_from<base> half_type>[[nodiscard]](half_type lhs, half_type rhs) {
			return xte::as_xvalue(lhs) >> xte::as_xvalue(rhs);
		}
	};

	inline constexpr auto lshift = xte::visitor {
		XTE_LIFT(xte::lshift),
		[]<xte::is_privately_derived_from<base> half_type>[[nodiscard]](half_type lhs, half_type rhs) {
			return xte::as_xvalue(lhs) << xte::as_xvalue(rhs);
		}
	};

	inline constexpr auto is_single_bit = xte::visitor {
		XTE_LIFT(xte::is_single_bit),
		[][[nodiscard]](this auto is_single_bit, xte::is_privately_derived_from<base> auto x) {
			return is_single_bit(x.lo) != is_single_bit(x.hi);
		}
	};

	inline constexpr auto leading_zeros = xte::visitor {
		XTE_LIFT(xte::leading_zeros),
		[][[nodiscard]](this auto leading_zeros, xte::is_privately_derived_from<base> auto x) {
			return x.hi ? leading_zeros(x.hi) : (leading_zeros(x.lo) + width<typename decltype(x)::value_type>);
		}
	};

	inline constexpr auto trailing_zeros = xte::visitor {
		XTE_LIFT(xte::trailing_zeros),
		[][[nodiscard]](this auto trailing_zeros, xte::is_privately_derived_from<base> auto x) {
			return x.lo ? trailing_zeros(x.lo) : (trailing_zeros(x.hi) + width<typename decltype(x)::value_type>);
		}
	};

	template<typename half_type, char... digits>
	[[nodiscard]] static constexpr half_type parse() noexcept(false) {
		static constexpr xte::uz radix = xte::literal::radix::operator""_radix<digits...>();
		half_type result = 0;
		for (char digit : xte::fixed_array { digits... } | std::views::drop(2 * ((radix == 16) || (radix == 2)))) {
			if (digit == '\'') {
				continue;
			}
			xte::uz index = xte::string_view("0123456789ABCDEF").subview(0, radix).find(xte::uppercase(digit));
			if (!~index) {
				throw xte::static_error<"digit outside radix">();
			}
			(result *= static_cast<half_type>(radix)) += static_cast<half_type>(index);
		}
		return result;
	}
};

namespace xte {
	template<typename half_type>
	requires(xte::is_unsigned_int<half_type> || xte::is_privately_derived_from<half_type, DETAIL_XTE::wide_int::base>)
	struct wide_int : private DETAIL_XTE::wide_int::base {
	private:
		[[nodiscard]] constexpr xte::wide_int<half_type> _div(xte::wide_int<half_type> const& rhs) & noexcept {
			xte::wide_int<half_type> quot;
			while (true) {
				xte::wide_int<half_type> tmp = rhs;
				if (*this < tmp) {
					break;
				}
				xte::uz shift = DETAIL_XTE::wide_int::leading_zeros(tmp) - DETAIL_XTE::wide_int::leading_zeros(*this);
				tmp <<= shift;
				if (tmp > *this) {
					tmp >>= 1;
					--shift;
				}
				quot |= xte::wide_int<half_type>(1) << shift;
				*this -= tmp;
			}
			return quot;
		}

	public:
		using value_type = half_type;

		half_type lo;
		half_type hi;

		[[nodiscard]] constexpr wide_int(half_type lo, half_type hi) noexcept
		: lo(xte::as_xvalue(lo)), hi(xte::as_xvalue(hi)) {}

		template<typename int_type = half_type>
		requires(xte::is_int<int_type> || xte::is_privately_derived_from<int_type, DETAIL_XTE::wide_int::base>)
		[[nodiscard]] constexpr explicit(false) wide_int(int_type x = 0) noexcept
		: lo(static_cast<half_type>(x))
		, hi(static_cast<half_type>(DETAIL_XTE::wide_int::rshift(xte::as_xvalue(x), DETAIL_XTE::wide_int::width<half_type>))) {}

		template<typename int_type>
		requires(xte::is_int<int_type> || xte::is_privately_derived_from<int_type, DETAIL_XTE::wide_int::base>)
		[[nodiscard]] constexpr explicit operator int_type() const noexcept {
			return static_cast<int_type>(this->lo) | DETAIL_XTE::wide_int::lshift(static_cast<int_type>(this->hi), DETAIL_XTE::wide_int::width<half_type>);
		}

		[[nodiscard]] constexpr explicit operator bool() const noexcept {
			return this->lo || this->hi;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::wide_int<half_type> const& lhs, xte::wide_int<half_type> const& rhs) noexcept {
			if (auto order = lhs.hi <=> rhs.hi; !std::is_eq(order)) {
				return order;
			}
			return lhs.lo <=> rhs.lo;
		}

		[[nodiscard]] friend constexpr bool operator==(xte::wide_int<half_type> const& lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] constexpr xte::wide_int<half_type> operator+() const noexcept {
			return *this;
		}

		constexpr xte::wide_int<half_type>& operator++() & noexcept {
			return *this += 1;
		}

		[[nodiscard]] constexpr xte::wide_int<half_type> operator++(int) & noexcept {
			return xte::exchange(*this, *this + 1);
		}

		constexpr xte::wide_int<half_type>& operator+=(xte::wide_int<half_type> const& rhs) & noexcept {
			return *this = xte::wide_int<half_type>(this->lo + rhs.lo, this->hi + static_cast<half_type>(rhs.hi + ((static_cast<half_type>(-1) - this->lo) < rhs.lo)));
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator+(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs += rhs;
		}

		[[nodiscard]] constexpr xte::wide_int<half_type> operator-() const noexcept {
			return xte::wide_int<half_type>(~this->lo, ~this->hi) + 1;
		}

		constexpr xte::wide_int<half_type>& operator--() & noexcept {
			return *this -= 1;
		}

		[[nodiscard]] constexpr xte::wide_int<half_type> operator--(int) & noexcept {
			return xte::exchange(*this, *this - 1);
		}

		constexpr xte::wide_int<half_type>& operator-=(xte::wide_int<half_type> const& rhs) & noexcept {
			return *this = xte::wide_int<half_type>(this->lo - rhs.lo, static_cast<half_type>(this->hi - rhs.hi - (this->lo < rhs.lo)));
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator-(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs -= rhs;
		}

		constexpr xte::wide_int<half_type>& operator*=(xte::wide_int<half_type> const& rhs) & noexcept {
			static constexpr xte::uz half_size = DETAIL_XTE::wide_int::width<half_type> / 2;
			static constexpr half_type half_bits = static_cast<half_type>(-1) >> half_size;
			if (!*this || !rhs || !(this->lo || rhs.lo)) {
				return *this = 0;
			}
			if (!this->hi && !rhs.hi && ((xte::digits(this->lo, 2) + xte::digits(rhs.lo, 2)) <= DETAIL_XTE::wide_int::width<half_type>)) {
				this->lo *= rhs.lo;
				return *this;
			}
			if (!this->lo && !rhs.lo) {
				this->hi *= rhs.hi;
				return *this;
			}
			if (!rhs.hi && DETAIL_XTE::wide_int::is_single_bit(rhs.lo)) {
				return *this <<= DETAIL_XTE::wide_int::trailing_zeros(rhs.lo);
			}
			if (!rhs.lo && DETAIL_XTE::wide_int::is_single_bit(rhs.hi)) {
				return (*this <<= DETAIL_XTE::wide_int::trailing_zeros(rhs.hi)) <<= DETAIL_XTE::wide_int::width<half_type>;
			}
			xte::wide_int<half_type> prod = 0;
			half_type lhs_lo_lo = this->lo & half_bits;
			half_type lhs_lo_hi = this->lo >> half_size;
			half_type rhs_lo_lo = rhs.lo & half_bits;
			half_type rhs_lo_hi = rhs.lo >> half_size;
			half_type lo0 = lhs_lo_lo * rhs_lo_lo;
			half_type lo1 = lhs_lo_lo * rhs_lo_hi;
			half_type lo2 = lhs_lo_hi * rhs_lo_lo;
			prod.lo = static_cast<half_type>(lo0 + (lo1 << half_size) + (lo2 << half_size));
			prod.hi = static_cast<half_type>(lhs_lo_hi * rhs_lo_hi + (lo1 >> half_size) + (lo2 >> half_size) + ((((lo0 >> half_size) + (lo1 & half_bits) + (lo2 & half_bits)) >> half_size) & half_bits));
			if (this->lo && rhs.hi) {
				half_type rhs_hi_lo = rhs.hi & half_bits;
				prod.hi += static_cast<half_type>(lhs_lo_lo * rhs_hi_lo + ((lhs_lo_lo * (rhs.hi >> half_size)) << half_size) + (((this->lo >> half_size) * rhs_hi_lo) << half_size));
			}
			if (this->hi && rhs.lo) {
				half_type lhs_hi_lo = this->hi & half_bits;
				prod.hi += static_cast<half_type>(lhs_hi_lo * rhs_lo_lo + ((lhs_hi_lo * (rhs.lo >> half_size)) << half_size) + (((this->hi >> half_size) * rhs_lo_lo) << half_size));
			}
			return *this = xte::as_xvalue(prod);
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator*(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs *= rhs;
		}

		constexpr xte::wide_int<half_type>& operator/=(xte::wide_int<half_type> const& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::static_error<"division by zero">();
			}
			if (!this->hi && !rhs.hi) {
				this->lo /= rhs.lo;
				return *this;
			}
			if (DETAIL_XTE::wide_int::is_single_bit(rhs)) {
				return *this >>= DETAIL_XTE::wide_int::trailing_zeros(rhs);
			}
			return *this = this->_div(rhs);
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator/(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept(false) {
			return lhs /= rhs;
		}

		constexpr xte::wide_int<half_type>& operator%=(xte::wide_int<half_type> const& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::static_error<"remainder of division by zero">();
			}
			if (!this->hi && !rhs.hi) {
				this->lo %= rhs.lo;
				return *this;
			}
			if (!this->lo && !rhs.lo) {
				this->hi %= rhs.hi;
				return *this;
			}
			if (DETAIL_XTE::wide_int::is_single_bit(rhs)) {
				return *this &= rhs - 1;
			}
			(void)this->_div(rhs);
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator%(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept(false) {
			return lhs %= rhs;
		}

		[[nodiscard]] constexpr xte::wide_int<half_type> operator~() const noexcept {
			return xte::wide_int<half_type>(~this->lo, ~this->hi);
		}

		constexpr xte::wide_int<half_type>& operator&=(xte::wide_int<half_type> const& rhs) & noexcept {
			this->lo &= rhs.lo;
			this->hi &= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator&(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs &= rhs;
		}

		constexpr xte::wide_int<half_type>& operator|=(xte::wide_int<half_type> const& rhs) & noexcept {
			this->lo |= rhs.lo;
			this->hi |= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator|(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs |= rhs;
		}

		constexpr xte::wide_int<half_type>& operator^=(xte::wide_int<half_type> const& rhs) & noexcept {
			this->lo ^= rhs.lo;
			this->hi ^= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator^(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs ^= rhs;
		}

		constexpr xte::wide_int<half_type>& operator<<=(xte::wide_int<half_type> const& rhs) & noexcept {
			if (rhs.hi) {
				return *this = 0;
			}
			if (auto shift = static_cast<xte::uz>(rhs.lo)) {
				auto min = xte::min(shift, DETAIL_XTE::wide_int::width<half_type>);
				this->hi = DETAIL_XTE::wide_int::lshift(this->hi, shift) | DETAIL_XTE::wide_int::lshift(DETAIL_XTE::wide_int::rshift(this->lo, DETAIL_XTE::wide_int::width<half_type> - min), shift - min);
				this->lo = DETAIL_XTE::wide_int::lshift(this->lo, shift);
			}
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator<<(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs <<= rhs;
		}

		constexpr xte::wide_int<half_type>& operator>>=(xte::wide_int<half_type> const& rhs) & noexcept {
			if (rhs.hi) {
				return *this = 0;
			}
			if (auto shift = static_cast<xte::uz>(rhs.lo)) {
				auto min = xte::min(shift, DETAIL_XTE::wide_int::width<half_type>);
				this->lo = DETAIL_XTE::wide_int::rshift(this->lo, shift) | DETAIL_XTE::wide_int::rshift(DETAIL_XTE::wide_int::lshift(this->hi, DETAIL_XTE::wide_int::width<half_type> - min), shift - min);
				this->hi = DETAIL_XTE::wide_int::rshift(this->hi, shift);
			}
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_int<half_type> operator>>(xte::wide_int<half_type> lhs, xte::wide_int<half_type> const& rhs) noexcept {
			return lhs >>= rhs;
		}
	};

	template<typename half_type>
	wide_int(half_type) -> wide_int<xte::try_unsigned<half_type>>;
}

namespace xte::literal::wide_int {
#	if XTE_HAS_INT_8
	[[nodiscard]] consteval xte::wide_int<xte::u8> operator""_w16(unsigned long long x) noexcept {
		return xte::wide_int<xte::u8>(x);
	}
#	endif
#	if XTE_HAS_INT_16
	[[nodiscard]] consteval xte::wide_int<xte::u16> operator""_w32(unsigned long long x) noexcept {
		return xte::wide_int<xte::u16>(x);
	}
#	endif
#	if XTE_HAS_INT_32
	[[nodiscard]] consteval xte::wide_int<xte::u32> operator""_w64(unsigned long long x) noexcept {
		return xte::wide_int<xte::u32>(x);
	}
#	endif
#	if XTE_HAS_INT_64
	template<char... digits>
	[[nodiscard]] consteval xte::wide_int<xte::u64> operator""_w128() noexcept {
		return DETAIL_XTE::wide_int::parse<xte::wide_int<xte::u64>, digits...>();
	}

	template<char... digits>
	[[nodiscard]] consteval xte::wide_int<xte::wide_int<xte::u64>> operator""_w256() noexcept {
		return DETAIL_XTE::wide_int::parse<xte::wide_int<xte::wide_int<xte::u64>>, digits...>();
	}
#	endif
}

template<typename half_type>
struct std::formatter<xte::wide_int<half_type>> {
	constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	auto format(xte::wide_int<half_type> x, std::format_context& ctx) const noexcept(false) {
		xte::string result;
		do {
			result += static_cast<char>((x % 10).lo + '0');
		} while (x /= 10);
		std::ranges::reverse(result);
		return std::format_to(ctx.out(), "{}", result);
	}
};

#endif
