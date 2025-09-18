#ifndef DETAIL_XIEITE_HEADER_MATH_DOUBLE_UINT
#	define DETAIL_XIEITE_HEADER_MATH_DOUBLE_UINT
#
#	include <bit>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <stdexcept>
#	include <utility>
#	include "../math/add_overflow.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/left_shift.hpp"
#	include "../math/right_shift.hpp"

namespace xieite {
	template<std::unsigned_integral UInt>
	struct wide_uint {
		UInt lo;
		UInt hi;

		[[nodiscard]] constexpr wide_uint(UInt lo, UInt hi) noexcept
		: lo(lo), hi(hi) {}

		template<std::integral Int = UInt>
		[[nodiscard]] explicit(false) constexpr wide_uint(Int x = 0) noexcept
		: lo(static_cast<UInt>(x) & static_cast<UInt>(-1))
		, hi(xieite::right_shift(static_cast<UInt>(x), xieite::bit_size<UInt>))
		{}

		template<std::integral Int>
		[[nodiscard]] explicit constexpr operator Int() const noexcept {
			return static_cast<Int>(this->lo) | xieite::left_shift(static_cast<Int>(this->hi), xieite::bit_size<UInt>);
		}
		
		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return this->lo || this->hi;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			std::strong_ordering order = lhs.hi <=> rhs.hi;
			return !std::is_eq(order) || (order = lhs.lo <=> rhs.lo, true), order;
		}

		[[nodiscard]] friend constexpr bool operator==(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] constexpr xieite::wide_uint<UInt> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator+(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return xieite::wide_uint<UInt>(lhs.lo + rhs.lo, static_cast<UInt>(lhs.hi + rhs.hi + xieite::add_overflow(lhs.lo, rhs.lo)));
		}

		constexpr xieite::wide_uint<UInt>& operator+=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::wide_uint<UInt>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::wide_uint<UInt> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::wide_uint<UInt> operator-() const noexcept {
			return xieite::wide_uint<UInt>(~this->lo, ~this->hi) + 1;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator-(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return xieite::wide_uint<UInt>(lhs.lo - rhs.lo, static_cast<UInt>(lhs.hi - rhs.hi - (lhs.lo < rhs.lo)));
		}

		constexpr xieite::wide_uint<UInt>& operator-=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::wide_uint<UInt>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::wide_uint<UInt> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator*(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			static constexpr UInt half_size = xieite::bit_size<UInt> / 2;
			static constexpr UInt half_bits = static_cast<UInt>(-1) >> half_size;
			if (!lhs || !rhs) {
				return 0;
			}
			if (std::has_single_bit(rhs.lo) && !rhs.hi) {
				return lhs << xieite::wide_uint<UInt>(std::countr_zero(rhs.lo));
			}
			if (!rhs.lo && std::has_single_bit(rhs.hi)) {
				return lhs << xieite::wide_uint<UInt>(static_cast<std::size_t>(std::countr_zero(rhs.hi)) + xieite::bit_size<UInt>);
			}
			xieite::wide_uint<UInt> prod;
			if (lhs.lo && rhs.lo) {
				const UInt lhs_lo_lo = lhs.lo & half_bits;
				const UInt lhs_lo_hi = lhs.lo >> half_size;
				const UInt rhs_lo_lo = rhs.lo & half_bits;
				const UInt rhs_lo_hi = rhs.lo >> half_size;
				const UInt prod_lo0 = lhs_lo_lo * rhs_lo_lo;
				const UInt prod_lo1 = lhs_lo_lo * rhs_lo_hi;
				const UInt prod_lo2 = lhs_lo_hi * rhs_lo_lo;
				prod.lo = static_cast<UInt>(prod_lo0 + (prod_lo1 << half_size) + (prod_lo2 << half_size));
				prod.hi = static_cast<UInt>(lhs_lo_hi * rhs_lo_hi + (prod_lo1 >> half_size) + (prod_lo2 >> half_size) + ((((prod_lo0 >> half_size) + (prod_lo1 & half_bits) + (prod_lo2 & half_bits)) >> half_size) & half_bits));
			}
			if (lhs.hi && rhs.hi) {
				const UInt lhs_hi_lo = lhs.hi & half_bits;
				const UInt rhs_hi_lo = rhs.hi & half_bits;
				prod.hi += static_cast<UInt>(lhs_hi_lo * rhs_hi_lo + ((lhs_hi_lo * (rhs.hi >> half_size)) << half_size) + (((lhs.hi >> half_size) * rhs_hi_lo) << half_size));
			}
			return prod;
		}

		constexpr xieite::wide_uint<UInt>& operator*=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this * rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator/(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) {
			if (!rhs.lo && !rhs.hi) {
				throw std::out_of_range("must not divide by zero");
			}
			if (rhs == 1) {
				return lhs;
			}
			if (lhs < rhs) {
				return 0;
			}
			if (lhs == rhs) {
				return 1;
			}
			if (std::has_single_bit(rhs.lo) && !rhs.hi) {
				return lhs >> xieite::wide_uint<UInt>(std::countr_zero(rhs.lo));
			}
			if (!rhs.lo && std::has_single_bit(rhs.hi)) {
				return lhs.hi >> static_cast<UInt>(std::countr_zero(rhs.hi));
			}
			xieite::wide_uint<UInt> rem;
			xieite::wide_uint<UInt> quot;
			for (std::size_t i = xieite::bit_size<UInt> * 2; i--;) {
				rem <<= 1;
				UInt bit;
				if (i >= xieite::bit_size<UInt>) {
					bit = (lhs.hi >> (i - xieite::bit_size<UInt>)) & 1;
				} else {
					bit = (lhs.lo >> i) & 1;
				}
				rem.lo |= bit;
				if (rem >= rhs) {
					rem -= rhs;
					if (i >= xieite::bit_size<UInt>) {
						quot.hi |= static_cast<UInt>(1) << (i - xieite::bit_size<UInt>);
					} else {
						quot.lo |= static_cast<UInt>(1) << i;
					}
				}
			}
			return quot;
		}

		constexpr xieite::wide_uint<UInt>& operator/=(xieite::wide_uint<UInt> rhs) {
			return *this = *this / rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator%(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) {
			if (!rhs.lo && !rhs.hi) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			if (lhs < rhs) {
				return lhs;
			}
			if (lhs == rhs) {
				return 0;
			}
			if ((std::has_single_bit(rhs.lo) && !rhs.hi) || (!rhs.lo && std::has_single_bit(rhs.hi))) {
				return lhs & (rhs - 1);
			}
			xieite::wide_uint<UInt> rem;
			for (std::size_t i = xieite::bit_size<UInt> * 2; i--;) {
				rem <<= 1;
				UInt bit;
				if (i >= xieite::bit_size<UInt>) {
					bit = (lhs.hi >> (i - xieite::bit_size<UInt>)) & 1;
				} else {
					bit = (lhs.lo >> i) & 1;
				}
				rem.lo |= bit;
				if (rem >= rhs) {
					rem -= rhs;
				}
			}
			return rem;
		}

		constexpr xieite::wide_uint<UInt>& operator%=(xieite::wide_uint<UInt> rhs) {
			return *this = *this % rhs;
		}

		[[nodiscard]] constexpr xieite::wide_uint<UInt> operator~() const noexcept {
			return xieite::wide_uint<UInt>(~this->lo, ~this->hi);
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator&(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return xieite::wide_uint<UInt>(lhs.lo & rhs.lo, lhs.hi & rhs.hi);
		}

		constexpr xieite::wide_uint<UInt>& operator&=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this & rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator|(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return xieite::wide_uint<UInt>(lhs.lo | rhs.lo, lhs.hi | rhs.hi);
		}

		constexpr xieite::wide_uint<UInt>& operator|=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this | rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator^(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			return xieite::wide_uint<UInt>(lhs.lo ^ rhs.lo, lhs.hi ^ rhs.hi);
		}

		constexpr xieite::wide_uint<UInt>& operator^=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this ^ rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator<<(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			if (!rhs.hi) {
				const std::size_t shift = static_cast<std::size_t>(rhs.lo);
				if (!shift) {
					return lhs;
				}
				if (shift < xieite::bit_size<UInt>) {
					return xieite::wide_uint<UInt>(static_cast<UInt>(lhs.lo << shift), static_cast<UInt>((lhs.hi << shift) | (lhs.lo >> (xieite::bit_size<UInt> - shift))));
				}
				if (shift < (xieite::bit_size<UInt> * 2)) {
					return xieite::wide_uint<UInt>(0, static_cast<UInt>(lhs.lo << (shift - xieite::bit_size<UInt>)));
				}
			}
			return xieite::wide_uint<UInt>(0, 0);
		}

		constexpr xieite::wide_uint<UInt>& operator<<=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this << rhs;
		}

		[[nodiscard]] friend constexpr xieite::wide_uint<UInt> operator>>(xieite::wide_uint<UInt> lhs, xieite::wide_uint<UInt> rhs) noexcept {
			if (!rhs.hi) {
				const std::size_t shift = static_cast<std::size_t>(rhs.lo);
				if (!shift) {
					return lhs;
				}
				if (shift < xieite::bit_size<UInt>) {
					return xieite::wide_uint<UInt>(static_cast<UInt>((lhs.lo >> shift) | (lhs.hi << (xieite::bit_size<UInt> - shift))), static_cast<UInt>(lhs.hi >> shift));
				}
				if (shift < (xieite::bit_size<UInt> * 2)) {
					return xieite::wide_uint<UInt>(static_cast<UInt>(lhs.hi >> (shift - xieite::bit_size<UInt>)), 0);
				}
			}
			return xieite::wide_uint<UInt>(0, 0);
		}

		constexpr xieite::wide_uint<UInt>& operator>>=(xieite::wide_uint<UInt> rhs) noexcept {
			return *this = *this >> rhs;
		}
	};
}

#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for fixing subtraction, division, and bitwise shifting operators
