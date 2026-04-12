#ifndef DETAIL_XTE_HEADER_MATH_WIDE_UINT
#	define DETAIL_XTE_HEADER_MATH_WIDE_UINT
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../data/uppercase.hpp"
#	include "../func/visitor.hpp"
#	include "../math/is_single_bit.hpp"
#	include "../math/leading_zeros.hpp"
#	include "../math/lshift.hpp"
#	include "../math/min.hpp"
#	include "../math/rshift.hpp"
#	include "../math/trailing_zeros.hpp"
#	include "../math/width.hpp"
#	include "../preproc/feature.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_privately_derived_from.hpp"
#	include "../trait/is_unsigned.hpp"
#	include "../util/error.hpp"
#	include "../util/exchange.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <algorithm>
#	include <compare>
#	include <initializer_list>
#	include <limits>

namespace DETAIL_XTE::wide_uint {
	struct base {};

	template<typename T>
	constexpr xte::uz width = xte::width<T>;

	template<xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> T>
	constexpr xte::uz width<T> = DETAIL_XTE::wide_uint::width<typename T::value_type>;

	inline constexpr auto rshift = xte::visitor {
		auto(xte::rshift),
		[]<xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> T>[[nodiscard]](T lhs, T rhs) {
			return xte::xvalue(lhs) >> xte::xvalue(rhs);
		}
	};

	inline constexpr auto lshift = xte::visitor {
		auto(xte::lshift),
		[]<xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> T>[[nodiscard]](T lhs, T rhs) {
			return xte::xvalue(lhs) << xte::xvalue(rhs);
		}
	};

	inline constexpr auto is_single_bit = xte::visitor {
		auto(xte::is_single_bit),
		[][[nodiscard]](this auto is_single_bit, xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> auto x) {
			return is_single_bit(x.lo) != is_single_bit(x.hi);
		}
	};

	inline constexpr auto leading_zeros = xte::visitor {
		auto(xte::leading_zeros),
		[][[nodiscard]](this auto leading_zeros, xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> auto x) {
			return x.hi ? leading_zeros(x.hi) : (leading_zeros(x.lo) + DETAIL_XTE::wide_uint::width<typename decltype(x)::value_type>);
		}
	};

	inline constexpr auto trailing_zeros = xte::visitor {
		auto(xte::trailing_zeros),
		[][[nodiscard]](this auto trailing_zeros, xte::is_privately_derived_from<DETAIL_XTE::wide_uint::base> auto x) {
			return x.lo ? trailing_zeros(x.lo) : (trailing_zeros(x.hi) + DETAIL_XTE::wide_uint::width<typename decltype(x)::value_type>);
		}
	};

	template<typename T, char... digits>
	[[nodiscard]] static consteval T parse() noexcept(false) {
		xte::uz radix = 10;
		if constexpr ((sizeof...(digits) > 2) && (digits...[0] == '0')) {
			switch (digits...[1]) {
				case 'X': case 'x':
					radix = 16;
					break;
				case 'B': case 'b':
					radix = 2;
					break;
			}
		}
		T result = 0;
		for (char digit : (xte::string { digits... }).slice((radix != 10) * 2)) {
			if (digit != '\'') {
				(result *= radix) += xte::string_view("0123456789ABCDEF").find(xte::uppercase(digit));
			}
		}
		return result;
	}
};

namespace xte {
	template<typename T>
	requires(xte::is_unsigned<T> || xte::is_privately_derived_from<T, DETAIL_XTE::wide_uint::base>)
	struct wide_uint : private DETAIL_XTE::wide_uint::base {
	private:
		[[nodiscard]] constexpr xte::wide_uint<T> _divide(const xte::wide_uint<T>& rhs) noexcept {
			xte::wide_uint<T> quot;
			while (true) {
				xte::wide_uint<T> tmp = rhs;
				if (*this < tmp) {
					break;
				}
				xte::uz shift = DETAIL_XTE::wide_uint::leading_zeros(tmp) - DETAIL_XTE::wide_uint::leading_zeros(*this);
				tmp <<= shift;
				if (tmp > *this) {
					tmp >>= 1;
					--shift;
				}
				quot |= xte::wide_uint<T>(1) << shift;
				*this -= tmp;
			}
			return quot;
		}

	public:
		using value_type = T;

		T lo;
		T hi;

		[[nodiscard]] constexpr wide_uint(T lo, T hi) noexcept
		: lo(xte::xvalue(lo)), hi(xte::xvalue(hi)) {}

		template<typename U = T>
		requires(xte::is_int<U> || xte::is_privately_derived_from<U, DETAIL_XTE::wide_uint::base>)
		[[nodiscard]] explicit(false) constexpr wide_uint(U x = 0) noexcept
		: lo(static_cast<T>(x))
		, hi(static_cast<T>(DETAIL_XTE::wide_uint::rshift(xte::xvalue(x), DETAIL_XTE::wide_uint::width<T>))) {}

		template<typename U>
		requires(xte::is_int<U> || xte::is_privately_derived_from<U, DETAIL_XTE::wide_uint::base>)
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			return static_cast<U>(this->lo) | DETAIL_XTE::wide_uint::lshift(static_cast<U>(this->hi), DETAIL_XTE::wide_uint::width<T>);
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return this->lo || this->hi;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xte::wide_uint<T>& lhs, const xte::wide_uint<T>& rhs) noexcept {
			if (auto order = lhs.hi <=> rhs.hi; !std::is_eq(order)) {
				return order;
			}
			return lhs.lo <=> rhs.lo;
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::wide_uint<T>& lhs, const xte::wide_uint<T>& rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] constexpr xte::wide_uint<T> operator+() const noexcept {
			return *this;
		}

		constexpr xte::wide_uint<T>& operator++() & noexcept {
			return *this += 1;
		}

		constexpr xte::wide_uint<T> operator++(int) & noexcept {
			return xte::exchange(*this, *this + 1);
		}

		constexpr xte::wide_uint<T>& operator+=(const xte::wide_uint<T>& rhs) & noexcept {
			return *this = xte::wide_uint<T>(this->lo + rhs.lo, this->hi + static_cast<T>(rhs.hi + ((static_cast<T>(-1) - this->lo) < rhs.lo)));
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator+(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs += rhs;
		}

		[[nodiscard]] constexpr xte::wide_uint<T> operator-() const noexcept {
			return xte::wide_uint<T>(~this->lo, ~this->hi) + 1;
		}

		constexpr xte::wide_uint<T>& operator--() & noexcept {
			return *this -= 1;
		}

		constexpr xte::wide_uint<T> operator--(int) & noexcept {
			return xte::exchange(*this, *this - 1);
		}

		constexpr xte::wide_uint<T>& operator-=(const xte::wide_uint<T>& rhs) & noexcept {
			return *this = xte::wide_uint<T>(this->lo - rhs.lo, static_cast<T>(this->hi - rhs.hi + (this->lo < rhs.lo)));
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator-(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs -= rhs;
		}

		constexpr xte::wide_uint<T>& operator*=(const xte::wide_uint<T>& rhs) & noexcept {
			static constexpr xte::uz half_size = DETAIL_XTE::wide_uint::width<T> / 2;
			static constexpr T half_bits = static_cast<T>(-1) >> half_size;
			if (!*this || !rhs || !(this->lo || rhs.lo)) {
				return *this = 0;
			}
			if (!rhs.hi && DETAIL_XTE::wide_uint::is_single_bit(rhs.lo)) {
				return *this <<= DETAIL_XTE::wide_uint::trailing_zeros(rhs.lo);
			}
			if (!rhs.lo && DETAIL_XTE::wide_uint::is_single_bit(rhs.hi)) {
				return (*this <<= DETAIL_XTE::wide_uint::trailing_zeros(rhs.hi)) <<= DETAIL_XTE::wide_uint::width<T>;
			}
			xte::wide_uint<T> prod = 0;
			T lhs_lo_lo = this->lo & half_bits;
			T lhs_lo_hi = this->lo >> half_size;
			T rhs_lo_lo = rhs.lo & half_bits;
			T rhs_lo_hi = rhs.lo >> half_size;
			T lo0 = lhs_lo_lo * rhs_lo_lo;
			T lo1 = lhs_lo_lo * rhs_lo_hi;
			T lo2 = lhs_lo_hi * rhs_lo_lo;
			prod.lo = static_cast<T>(lo0 + (lo1 << half_size) + (lo2 << half_size));
			prod.hi = static_cast<T>(lhs_lo_hi * rhs_lo_hi + (lo1 >> half_size) + (lo2 >> half_size) + ((((lo0 >> half_size) + (lo1 & half_bits) + (lo2 & half_bits)) >> half_size) & half_bits));
			if (this->lo && rhs.hi) {
				T rhs_hi_lo = rhs.hi & half_bits;
				prod.hi += static_cast<T>(lhs_lo_lo * rhs_hi_lo + ((lhs_lo_lo * (rhs.hi >> half_size)) << half_size) + (((this->lo >> half_size) * rhs_hi_lo) << half_size));
			}
			if (this->hi && rhs.lo) {
				T lhs_hi_lo = this->hi & half_bits;
				prod.hi += static_cast<T>(lhs_hi_lo * rhs_lo_lo + ((lhs_hi_lo * (rhs.lo >> half_size)) << half_size) + (((this->hi >> half_size) * rhs_lo_lo) << half_size));
			}
			return *this = xte::xvalue(prod);
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator*(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs *= rhs;
		}

		constexpr xte::wide_uint<T>& operator/=(const xte::wide_uint<T>& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::error("must not divide by zero");
			}
			if (!this->hi && !rhs.hi) {
				this->lo /= rhs.lo;
				return *this;
			}
			if (DETAIL_XTE::wide_uint::is_single_bit(rhs)) {
				return *this >>= DETAIL_XTE::wide_uint::trailing_zeros(rhs);
			}
			return *this = this->_divide(rhs);
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator/(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept(false) {
			return lhs /= rhs;
		}

		constexpr xte::wide_uint<T>& operator%=(const xte::wide_uint<T>& rhs) & noexcept(false) {
			if (!rhs) {
				throw xte::error("must not take remainder of division by zero");
			}
			for (auto part : { &xte::wide_uint<T>::lo, &xte::wide_uint<T>::hi }) {
				if (!this->*part && !rhs.*part) {
					this->*part %= rhs.*part;
					return *this;
				}
			}
			if (DETAIL_XTE::wide_uint::is_single_bit(rhs)) {
				return *this &= rhs - 1;
			}
			(void)this->_divide(rhs);
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator%(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept(false) {
			return lhs %= rhs;
		}

		[[nodiscard]] constexpr xte::wide_uint<T> operator~() const noexcept {
			return xte::wide_uint<T>(~this->lo, ~this->hi);
		}

		constexpr xte::wide_uint<T>& operator&=(const xte::wide_uint<T>& rhs) & noexcept {
			this->lo &= rhs.lo;
			this->hi &= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator&(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs &= rhs;
		}

		constexpr xte::wide_uint<T>& operator|=(const xte::wide_uint<T>& rhs) & noexcept {
			this->lo |= rhs.lo;
			this->hi |= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator|(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs |= rhs;
		}

		constexpr xte::wide_uint<T>& operator^=(const xte::wide_uint<T>& rhs) & noexcept {
			this->lo ^= rhs.lo;
			this->hi ^= rhs.hi;
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator^(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs ^= rhs;
		}

		constexpr xte::wide_uint<T>& operator<<=(const xte::wide_uint<T>& rhs) & noexcept {
			if (rhs.hi) {
				return *this = 0;
			}
			if (const auto shift = static_cast<xte::uz>(rhs.lo)) {
				const auto min = xte::min(shift, DETAIL_XTE::wide_uint::width<T>);
				this->hi = DETAIL_XTE::wide_uint::lshift(this->hi, shift) | DETAIL_XTE::wide_uint::lshift(DETAIL_XTE::wide_uint::rshift(this->lo, DETAIL_XTE::wide_uint::width<T> - min), shift - min);
				this->lo = DETAIL_XTE::wide_uint::lshift(this->lo, shift);
			}
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator<<(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs <<= rhs;
		}

		constexpr xte::wide_uint<T>& operator>>=(const xte::wide_uint<T>& rhs) & noexcept {
			if (rhs.hi) {
				return *this = 0;
			}
			if (const auto shift = static_cast<xte::uz>(rhs.lo)) {
				const auto min = xte::min(shift, DETAIL_XTE::wide_uint::width<T>);
				this->lo = DETAIL_XTE::wide_uint::rshift(this->lo, shift) | DETAIL_XTE::wide_uint::rshift(DETAIL_XTE::wide_uint::lshift(this->hi, DETAIL_XTE::wide_uint::width<T> - min), shift - min);
				this->hi = DETAIL_XTE::wide_uint::rshift(this->hi, shift);
			}
			return *this;
		}

		[[nodiscard]] friend constexpr xte::wide_uint<T> operator>>(xte::wide_uint<T> lhs, const xte::wide_uint<T>& rhs) noexcept {
			return lhs >>= rhs;
		}
	};
}

namespace xte::literal::wide_uint {
#	if XTE_FEATURE_INT_8
	[[nodiscard]] consteval xte::wide_uint<xte::u8> operator""_w16(unsigned long long x) noexcept {
		return xte::wide_uint<xte::u8>(x);
	}
#	endif
#	if XTE_FEATURE_INT_16
	[[nodiscard]] consteval xte::wide_uint<xte::u16> operator""_w32(unsigned long long x) noexcept {
		return xte::wide_uint<xte::u16>(x);
	}
#	endif
#	if XTE_FEATURE_INT_32
	[[nodiscard]] consteval xte::wide_uint<xte::u32> operator""_w64(unsigned long long x) noexcept {
		return xte::wide_uint<xte::u32>(x);
	}
#	endif
#	if XTE_FEATURE_INT_64
	template<char... digits>
	[[nodiscard]] consteval xte::wide_uint<xte::u64> operator""_w128() noexcept {
		return DETAIL_XTE::wide_uint::parse<xte::wide_uint<xte::u64>, digits...>();
	}

	template<char... digits>
	[[nodiscard]] consteval xte::wide_uint<xte::wide_uint<xte::u64>> operator""_w256() noexcept {
		return DETAIL_XTE::wide_uint::parse<xte::wide_uint<xte::wide_uint<xte::u64>>, digits...>();
	}
#	endif
}

template<typename T>
struct std::formatter<xte::wide_uint<T>> {
	constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	auto format(xte::wide_uint<T> x, std::format_context& ctx) const noexcept(false) {
		xte::string result;
		do {
			result += static_cast<char>(x.lo % 10) + '0';
		} while (x /= 10);
		std::ranges::reverse(result);
		return std::format_to(ctx.out(), "{}", result);
	}
};

#endif
