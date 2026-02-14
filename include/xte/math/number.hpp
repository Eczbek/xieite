#ifndef DETAIL_XTE_HEADER_MATH_NUMBER
#	define DETAIL_XTE_HEADER_MATH_NUMBER
#
#	include "../math/abs.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../math/lshift.hpp"
#	include "../math/rem.hpp"
#	include "../math/rshift.hpp"
#	include "../math/try_signed.hpp"
#	include "../math/try_unsigned.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_same_any.hpp"
#	include "../trait/is_same_any_ignore_cvref.hpp"
#	include "../util/exchange.hpp"
#	include <cmath>
#	include <compare>
#	include <limits>

namespace xte {
	template<xte::is_number T>
	struct number {
		using type = T;

		T value;

		template<typename U = T>
		[[nodiscard]] explicit(!xte::is_same_any_ignore_cvref<U, xte::try_unsigned<T>, xte::try_signed<T>>)
		constexpr number(U&& x = 0) XTE_ARROW_CTOR(,
			value,((static_cast<T>(XTE_FWD(x))))
		)

		template<typename U>
		[[nodiscard]] explicit(!xte::is_same_any<U, xte::try_unsigned<T>, xte::try_signed<T>>)
		constexpr operator U() const XTE_ARROW(
			static_cast<U>(this->value)
		)

		constexpr auto&& operator=(this auto&& lhs, T rhs) noexcept {
			lhs.value = rhs.value;
			return XTE_FWD(lhs);
		}

		constexpr auto&& operator=(this auto&& lhs, auto&& rhs) XTE_ARROW(
			lhs = xte::number<T>(XTE_FWD(rhs))
		)

		template<typename U>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs.value <=> rhs.value;
		}

		[[nodiscard]] friend constexpr auto operator<=>(xte::number<T> lhs, auto&& rhs) XTE_ARROW(
			lhs.value <=> rhs
		}

		template<typename U>
		[[nodiscard]] friend constexpr bool operator==(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs.value == rhs.value;
		}

		[[nodiscard]] constexpr xte::number<T> operator+() const noexcept {
			return *this;
		}

		constexpr auto&& operator+=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::as_unsigned(lhs.value) + xte::as_unsigned(rhs);
		}

		[[nodiscard]] friend constexpr xte::number<T> operator+(xte::number<T> lhs, T rhs) noexcept {
			return lhs += rhs;
		}

		constexpr auto&& operator++(this auto&& lhs) noexcept {
			return lhs += 1;
		}

		constexpr xte::number<T> operator++(int) noexcept {
			return xte::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xte::number<T> operator-() const noexcept {
			return -xte::as_unsigned(*this);
		}

		constexpr auto&& operator-=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::as_unsigned(lhs.value) - xte::as_unsigned(rhs);
		}

		[[nodiscard]] friend constexpr xte::number<T> operator-(xte::number<T> lhs, T rhs) noexcept {
			return lhs -= rhs;
		}

		constexpr auto&& operator--(this auto&& lhs) noexcept {
			return lhs -= 1;
		}

		constexpr xte::number<T> operator--(int) noexcept {
			return xte::exchange(*this, *this - 1);
		}

		constexpr auto&& operator*=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::as_unsigned(lhs.value) * xte::as_unsigned(rhs);
		}

		[[nodiscard]] friend constexpr xte::number<T> operator*(xte::number<T> lhs, T rhs) noexcept {
			return lhs *= rhs;
		}

		constexpr auto&& operator/=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::as_unsigned(lhs.value) / xte::as_unsigned(rhs);
		}

		[[nodiscard]] friend constexpr xte::number<T> operator/(xte::number<T> lhs, T rhs) noexcept {
			return lhs /= rhs;
		}

		constexpr auto&& operator%=(this auto&& lhs, T rhs) noexcept {
			return xte::rem(lhs.value, rhs);
		}

		[[nodiscard]] friend constexpr xte::number<T> operator%(xte::number<T> lhs, T rhs) noexcept {
			return lhs %= rhs;
		}

		[[nodiscard]] constexpr xte::number<T> operator~() const noexcept {
			if constexpr (xte::is_float<T>) {
				return -this->value - 1;
			} else {
				return ~this->value;
			}
		}

		constexpr auto&& operator&=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::number<T>::bit_op(lhs.value, rhs, XTE_LIFT_INFIX(&));
		}

		[[nodiscard]] friend constexpr xte::number<T> operator&(xte::number<T> lhs, T rhs) noexcept {
			return lhs &= rhs;
		}

		constexpr auto&& operator|=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::number<T>::bit_op(lhs.value, rhs, XTE_LIFT_INFIX(|));
		}

		[[nodiscard]] friend constexpr xte::number<T> operator|(xte::number<T> lhs, T rhs) noexcept {
			return lhs |= rhs;
		}

		constexpr auto&& operator^=(this auto&& lhs, T rhs) noexcept {
			return lhs = xte::number<T>::bit_op(lhs.value, rhs, XTE_LIFT_INFIX(^));
		}

		[[nodiscard]] friend constexpr xte::number<T> operator^(xte::number<T> lhs, T rhs) noexcept {
			return lhs ^= rhs;
		}

		constexpr auto&& operator<<=(this auto&& lhs, T rhs) noexcept {
			if constexpr (xte::is_float<T>) {
				return lhs = lhs.value * std::pow(2, rhs);
			} else {
				if (rhs < 0) {
					return lhs >>= xte::abs(rhs);
				}
				return lhs = xte::lshift(lhs.value, rhs);
			}
		}

		[[nodiscard]] friend constexpr xte::number<T> operator<<(xte::number<T> lhs, T rhs) noexcept {
			return lhs <<= rhs;
		}

		constexpr auto&& operator>>=(this auto&& lhs, T rhs) noexcept {
			if constexpr (xte::is_float<T>) {
				return lhs = lhs.value / std::pow(2, rhs);
			} else {
				if (rhs < 0) {
					return lhs <<= xte::abs(rhs);
				}
				return lhs = xte::rshift(lhs.value, rhs);
			}
		}

		[[nodiscard]] friend constexpr xte::number<T> operator>>(xte::number<T> lhs, T rhs) noexcept {
			return lhs >>= rhs;
		}

	private:
		[[nodiscard]] static constexpr xte::number<T> bit_op(xte::number<T> lhs, xte::number<T> rhs, auto op) noexcept {
			if constexpr (xte::is_float<T>) {
				T result = 0;
				T mask = std::numeric_limits<T>::min();
				while (mask <= std::numeric_limits<T>::max()) {
					mask <<= 1;
					if (op(std::fmod(lhs.value, mask) >= mask, std::fmod(rhs.value, mask) >= mask)) {
						result += mask >> 1;
					}
				}
				return result;
			} else {
				return op(lhs.value, rhs.value);
			}
		}
	};

	template<typename T>
	number(T) -> number<T>;
}

#endif
