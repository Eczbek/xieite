#ifndef DETAIL_XIEITE_HEADER_MATH_DOUBLE_UINT
#	define DETAIL_XIEITE_HEADER_MATH_DOUBLE_UINT
#
#	include <bit>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <stdexcept>
#	include <utility>
#	include "../fn/order_op.hpp"
#	include "../math/add_overflow.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/lshift.hpp"
#	include "../math/rshift.hpp"

namespace xieite {
	template<std::unsigned_integral T>
	struct double_uint {
		T lo;
		T hi;

		[[nodiscard]] constexpr double_uint(T lo, T hi) noexcept
		: lo(lo), hi(hi) {}

		template<std::integral U = T>
		[[nodiscard]] explicit(false) constexpr double_uint(U x = 0) noexcept
		: lo(static_cast<T>(x & static_cast<T>(-1))), hi(static_cast<T>(xieite::rshift(x, xieite::bit_size<T>))) {}

		template<std::integral U>
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			return static_cast<U>(this->lo) | xieite::lshift(static_cast<U>(this->hi), xieite::bit_size<T>);
		}
		
		[[nodiscard]] explicit(false) constexpr operator bool() const noexcept {
			return this->lo || this->hi;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			using namespace xieite::order_op;
			return (l.hi <=> r.hi) | (l.lo <=> r.lo);
		}

		[[nodiscard]] friend constexpr bool operator==(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return std::is_eq(l <=> r);
		}

		[[nodiscard]] constexpr xieite::double_uint<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator+(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return xieite::double_uint<T>(l.lo + r.lo, static_cast<T>(l.hi + r.hi + xieite::add_overflow(l.lo, r.lo)));
		}

		constexpr xieite::double_uint<T>& operator+=(xieite::double_uint<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr xieite::double_uint<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::double_uint<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::double_uint<T> operator-() const noexcept {
			return xieite::double_uint<T>(~this->lo, ~this->hi) + 1;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator-(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return xieite::double_uint<T>(l.lo - r.lo, static_cast<T>(l.hi - r.hi - (l.lo < r.lo)));
		}

		constexpr xieite::double_uint<T>& operator-=(xieite::double_uint<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr xieite::double_uint<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::double_uint<T> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator*(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			static constexpr T half_size = xieite::bit_size<T> / 2;
			static constexpr T half_bits = static_cast<T>(-1) >> half_size;
			if (!l || !r) {
				return 0;
			}
			if (std::has_single_bit(r.lo) && !r.hi) {
				return l << xieite::double_uint<T>(std::countr_zero(r.lo));
			}
			if (!r.lo && std::has_single_bit(r.hi)) {
				return l << xieite::double_uint<T>(static_cast<std::size_t>(std::countr_zero(r.hi)) + xieite::bit_size<T>);
			}
			xieite::double_uint<T> prod;
			if (l.lo && r.lo) {
				const T l_lo_lo = l.lo & half_bits;
				const T l_lo_hi = l.lo >> half_size;
				const T r_lo_lo = r.lo & half_bits;
				const T r_lo_hi = r.lo >> half_size;
				const T prod_lo0 = l_lo_lo * r_lo_lo;
				const T prod_lo1 = l_lo_lo * r_lo_hi;
				const T prod_lo2 = l_lo_hi * r_lo_lo;
				prod.lo = static_cast<T>(prod_lo0 + (prod_lo1 << half_size) + (prod_lo2 << half_size));
				prod.hi = static_cast<T>(l_lo_hi * r_lo_hi + (prod_lo1 >> half_size) + (prod_lo2 >> half_size) + ((((prod_lo0 >> half_size) + (prod_lo1 & half_bits) + (prod_lo2 & half_bits)) >> half_size) & half_bits));
			}
			if (l.hi && r.hi) {
				const T l_hi_lo = l.hi & half_bits;
				const T r_hi_lo = r.hi & half_bits;
				prod.hi += static_cast<T>(l_hi_lo * r_hi_lo + ((l_hi_lo * (r.hi >> half_size)) << half_size) + (((l.hi >> half_size) * r_hi_lo) << half_size));
			}
			return prod;
		}

		constexpr xieite::double_uint<T>& operator*=(xieite::double_uint<T> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator/(xieite::double_uint<T> l, xieite::double_uint<T> r) {
			if (!r.lo && !r.hi) {
				throw std::out_of_range("must not divide by zero");
			}
			if (r == 1) {
				return l;
			}
			if (l < r) {
				return 0;
			}
			if (l == r) {
				return 1;
			}
			if (std::has_single_bit(r.lo) && !r.hi) {
				return l >> xieite::double_uint<T>(std::countr_zero(r.lo));
			}
			if (!r.lo && std::has_single_bit(r.hi)) {
				return l.hi >> static_cast<T>(std::countr_zero(r.hi));
			}
			xieite::double_uint<T> rem;
			xieite::double_uint<T> quot;
			for (std::size_t i = xieite::bit_size<T> * 2; i--;) {
				rem <<= 1;
				T bit;
				if (i >= xieite::bit_size<T>) {
					bit = (l.hi >> (i - xieite::bit_size<T>)) & 1;
				} else {
					bit = (l.lo >> i) & 1;
				}
				rem.lo |= bit;
				if (rem >= r) {
					rem -= r;
					if (i >= xieite::bit_size<T>) {
						quot.hi |= static_cast<T>(1) << (i - xieite::bit_size<T>);
					} else {
						quot.lo |= static_cast<T>(1) << i;
					}
				}
			}
			return quot;
		}

		constexpr xieite::double_uint<T>& operator/=(xieite::double_uint<T> r) {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator%(xieite::double_uint<T> l, xieite::double_uint<T> r) {
			if (!r.lo && !r.hi) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			if (l < r) {
				return l;
			}
			if (l == r) {
				return 0;
			}
			if ((std::has_single_bit(r.lo) && !r.hi) || (!r.lo && std::has_single_bit(r.hi))) {
				return l & (r - 1);
			}
			xieite::double_uint<T> rem;
			for (std::size_t i = xieite::bit_size<T> * 2; i--;) {
				rem <<= 1;
				T bit;
				if (i >= xieite::bit_size<T>) {
					bit = (l.hi >> (i - xieite::bit_size<T>)) & 1;
				} else {
					bit = (l.lo >> i) & 1;
				}
				rem.lo |= bit;
				if (rem >= r) {
					rem -= r;
				}
			}
			return rem;
		}

		constexpr xieite::double_uint<T>& operator%=(xieite::double_uint<T> r) {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr xieite::double_uint<T> operator~() const noexcept {
			return xieite::double_uint<T>(~this->lo, ~this->hi);
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator&(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return xieite::double_uint<T>(l.lo & r.lo, l.hi & r.hi);
		}

		constexpr xieite::double_uint<T>& operator&=(xieite::double_uint<T> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator|(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return xieite::double_uint<T>(l.lo | r.lo, l.hi | r.hi);
		}

		constexpr xieite::double_uint<T>& operator|=(xieite::double_uint<T> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator^(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			return xieite::double_uint<T>(l.lo ^ r.lo, l.hi ^ r.hi);
		}

		constexpr xieite::double_uint<T>& operator^=(xieite::double_uint<T> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator<<(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			if (!r.hi) {
				const std::size_t shift = static_cast<std::size_t>(r.lo);
				if (!shift) {
					return l;
				}
				if (shift < xieite::bit_size<T>) {
					return xieite::double_uint<T>(static_cast<T>(l.lo << shift), static_cast<T>((l.hi << shift) | (l.lo >> (xieite::bit_size<T> - shift))));
				}
				if (shift < (xieite::bit_size<T> * 2)) {
					return xieite::double_uint<T>(0, static_cast<T>(l.lo << (shift - xieite::bit_size<T>)));
				}
			}
			return xieite::double_uint<T>(0, 0);
		}

		constexpr xieite::double_uint<T>& operator<<=(xieite::double_uint<T> r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr xieite::double_uint<T> operator>>(xieite::double_uint<T> l, xieite::double_uint<T> r) noexcept {
			if (!r.hi) {
				const std::size_t shift = static_cast<std::size_t>(r.lo);
				if (!shift) {
					return l;
				}
				if (shift < xieite::bit_size<T>) {
					return xieite::double_uint<T>(static_cast<T>((l.lo >> shift) | (l.hi << (xieite::bit_size<T> - shift))), static_cast<T>(l.hi >> shift));
				}
				if (shift < (xieite::bit_size<T> * 2)) {
					return xieite::double_uint<T>(static_cast<T>(l.hi >> (shift - xieite::bit_size<T>)), 0);
				}
			}
			return xieite::double_uint<T>(0, 0);
		}

		constexpr xieite::double_uint<T>& operator>>=(xieite::double_uint<T> r) noexcept {
			return *this = *this >> r;
		}
	};
}

#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for fixing subtraction, division, and bitwise shifting operators
