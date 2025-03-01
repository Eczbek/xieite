#pragma once

#include <bit>
#include <compare>
#include <concepts>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include "../fn/ordop.hpp"
#include "../math/addovf.hpp"
#include "../math/bits.hpp"
#include "../math/lshift.hpp"
#include "../math/rshift.hpp"

namespace x4 {
	template<std::unsigned_integral T>
	struct duint {
		T lo;
		T hi;

		[[nodiscard]] constexpr duint() noexcept
		: lo(0), hi(0) {}

		[[nodiscard]] constexpr duint(T lo, T hi) noexcept
		: lo(lo), hi(hi) {}

		template<std::integral U>
		[[nodiscard]] explicit(false) constexpr duint(U x) noexcept
		: lo(static_cast<T>(x & static_cast<T>(-1))), hi(static_cast<T>(x4::rshift(x, x4::bits<T>))) {}

		template<std::integral U>
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			return static_cast<U>(this->lo) | x4::lshift(static_cast<U>(this->hi), x4::bits<T>);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(x4::duint<T> l, x4::duint<T> r) noexcept {
			using namespace x4::ordop;
			return (l.hi <=> r.hi) | (l.lo <=> r.lo);
		}

		[[nodiscard]] friend constexpr bool operator==(x4::duint<T> l, x4::duint<T> r) noexcept {
			return std::is_eq(l <=> r);
		}

		[[nodiscard]] constexpr x4::duint<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator+(x4::duint<T> l, x4::duint<T> r) noexcept {
			return x4::duint<T>(l.lo + r.lo, static_cast<T>(l.hi + r.hi + x4::addovf(l.lo, r.lo)));
		}

		constexpr x4::duint<T>& operator+=(x4::duint<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr x4::duint<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr x4::duint<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr x4::duint<T> operator-() const noexcept {
			return x4::duint<T>(~this->lo, ~this->hi) + 1;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator-(x4::duint<T> l, x4::duint<T> r) noexcept {
			return x4::duint<T>(l.lo - r.lo, static_cast<T>(l.hi - r.hi - (l.lo < r.lo)));
		}

		constexpr x4::duint<T>& operator-=(x4::duint<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr x4::duint<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr x4::duint<T> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator*(x4::duint<T> l, x4::duint<T> r) noexcept {
			static constexpr T half_size = x4::bits<T> / 2;
			static constexpr T half_bits = static_cast<T>(-1) >> half_size;
			x4::duint<T> prod;
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

		constexpr x4::duint<T>& operator*=(x4::duint<T> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator/(x4::duint<T> l, x4::duint<T> r) {
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
			if ((std::has_single_bit(r.lo) && !r.hi) || (!r.lo && std::has_single_bit(r.hi))) {
				if (std::has_single_bit(r.lo)) {
					return l >> std::countr_zero(r.lo);
				}
				return l.hi >> std::countr_zero(r.hi);
			}
			x4::duint<T> rem;
			x4::duint<T> quot;
			for (std::size_t i = x4::bits<T> * 2; i--;) {
				rem <<= 1;
				T bit;
				if (i >= x4::bits<T>) {
					bit = (l.hi >> (i - x4::bits<T>)) & 1;
				} else {
					bit = (l.lo >> i) & 1;
				}
				rem.lo |= bit;
				if (rem >= r) {
					rem -= r;
					if (i >= x4::bits<T>) {
						quot.hi |= static_cast<T>(1) << (i - x4::bits<T>);
					} else {
						quot.lo |= static_cast<T>(1) << i;
					}
				}
			}
			return quot;
		}

		constexpr x4::duint<T>& operator/=(x4::duint<T> r) {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator%(x4::duint<T> l, x4::duint<T> r) {
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
			x4::duint<T> rem;
			for (std::size_t i = x4::bits<T> * 2; i--;) {
				rem <<= 1;
				T bit;
				if (i >= x4::bits<T>) {
					bit = (l.hi >> (i - x4::bits<T>)) & 1;
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

		constexpr x4::duint<T>& operator%=(x4::duint<T> r) {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr x4::duint<T> operator~() const noexcept {
			return x4::duint<T>(~this->lo, ~this->hi);
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator&(x4::duint<T> l, x4::duint<T> r) noexcept {
			return x4::duint<T>(l.lo & r.lo, l.hi & r.hi);
		}

		constexpr x4::duint<T>& operator&=(x4::duint<T> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator|(x4::duint<T> l, x4::duint<T> r) noexcept {
			return x4::duint<T>(l.lo | r.lo, l.hi | r.hi);
		}

		constexpr x4::duint<T>& operator|=(x4::duint<T> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator^(x4::duint<T> l, x4::duint<T> r) noexcept {
			return x4::duint<T>(l.lo ^ r.lo, l.hi ^ r.hi);
		}

		constexpr x4::duint<T>& operator^=(x4::duint<T> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator<<(x4::duint<T> l, x4::duint<T> r) noexcept {
			if (!r.hi) {
				const std::size_t shift = static_cast<std::size_t>(r.lo);
				if (!shift) {
					return l;
				}
				if (shift < x4::bits<T>) {
					return x4::duint<T>(static_cast<T>(l.lo << shift), static_cast<T>((l.hi << shift) | (l.lo >> (x4::bits<T> - shift))));
				}
				if (shift < (x4::bits<T> * 2)) {
					return x4::duint<T>(0, static_cast<T>(l.lo << (shift - x4::bits<T>)));
				}
			}
			return x4::duint<T>(0, 0);
		}

		constexpr x4::duint<T>& operator<<=(x4::duint<T> r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr x4::duint<T> operator>>(x4::duint<T> l, x4::duint<T> r) noexcept {
			if (!r.hi) {
				const std::size_t shift = static_cast<std::size_t>(r.lo);
				if (!shift) {
					return l;
				}
				if (shift < x4::bits<T>) {
					return x4::duint<T>(static_cast<T>((l.lo >> shift) | (l.hi << (x4::bits<T> - shift))), static_cast<T>(l.hi >> shift));
				}
				if (shift < (x4::bits<T> * 2)) {
					return x4::duint<T>(static_cast<T>(l.hi >> (shift - x4::bits<T>)), 0);
				}
			}
			return x4::duint<T>(0, 0);
		}

		constexpr x4::duint<T>& operator>>=(x4::duint<T> r) noexcept {
			return *this = *this >> r;
		}
	};
}
