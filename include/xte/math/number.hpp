#ifndef DETAIL_XTE_HEADER_MATH_NUMBER
#	define DETAIL_XTE_HEADER_MATH_NUMBER
#
#	include "../math/abs.hpp"
#	include "../math/add.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../math/div.hpp"
#	include "../math/lshift.hpp"
#	include "../math/mul.hpp"
#	include "../math/pow.hpp"
#	include "../math/rem.hpp"
#	include "../math/sub.hpp"
#	include "../math/rshift.hpp"
#	include "../preproc/constructs.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_same_any.hpp"
#	include "../trait/is_same_any_drop_cvref.hpp"
#	include "../trait/try_signed.hpp"
#	include "../trait/try_unsigned.hpp"
#	include "../util/make.hpp"
#	include "../util/exchange.hpp"
#	include <compare>
#	include <limits>

namespace xte {
	template<xte::is_arithmetic T>
	struct number {
	private:
		constexpr void _bitwise(T rhs, auto func) noexcept {
			if constexpr (xte::is_float<T>) {
				T result = 0;
				T mask = std::numeric_limits<T>::min();
				while ((mask <= xte::abs(this->value)) || (mask <= xte::abs(rhs))) {
					if (func(xte::rem(xte::abs(this->value), mask * 2) >= mask, xte::rem(xte::abs(rhs), mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				this->value = func(this->value < 0, rhs < 0) ? -result : result;
			} else {
				this->value = func(this->value, rhs);
			}
		}

	public:
		using value_type = T;

		T value;

		template<typename U = T>
		[[nodiscard]] explicit(!xte::is_same_any_drop_cvref<U, xte::try_unsigned<T>, xte::try_signed<T>>)
		constexpr number(U&& x = 0) XTE_CONSTRUCTS(,
			value,((xte::make<T>(XTE_FWD(x))))
		)

		template<typename U>
		[[nodiscard]] explicit(!xte::is_same_any<U, xte::try_unsigned<T>, xte::try_signed<T>>)
		constexpr operator U() const noexcept {
			return xte::make<U>(this->value);
		}

		template<typename U>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return xte::approx_equal(lhs.value, rhs.value)
				? std::strong_ordering::equal
				: xte::less(lhs, rhs)
					? std::strong_ordering::less
					: std::strong_ordering::greater;
		}

		template<typename U>
		[[nodiscard]] friend constexpr bool operator==(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return xte::approx_equal(lhs.value, rhs.value);
		}

		[[nodiscard]] constexpr xte::number<T> operator+() const noexcept {
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator+(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs += rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator+(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs += rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator+=(xte::number<U> rhs) & noexcept {
			return *this += rhs.value;
		}

		constexpr xte::number<T>& operator+=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<T>(xte::add(this->value, rhs));
			return *this;
		}

		constexpr xte::number<T>& operator++() & noexcept {
			return *this += 1;
		}

		constexpr xte::number<T> operator++(int) noexcept {
			return xte::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xte::number<T> operator-() const noexcept {
			return xte::number<T>(-xte::as_unsigned(this->value));
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator-(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs -= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator-(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs -= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator-=(xte::number<U> rhs) & noexcept {
			return *this -= rhs.value;
		}

		constexpr xte::number<T>& operator-=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<T>(xte::sub(this->value, rhs));
			return *this;
		}

		constexpr xte::number<T>& operator--() & noexcept {
			return *this -= 1;
		}

		constexpr xte::number<T> operator--(int) noexcept {
			return xte::exchange(*this, *this - 1);
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator*(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs *= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator*(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs *= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator*=(xte::number<U> rhs) & noexcept {
			return *this *= rhs.value;
		}

		constexpr xte::number<T>& operator*=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<T>(xte::mul(this->value, rhs));
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator/(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs /= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator/(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs /= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator/=(xte::number<U> rhs) & noexcept {
			return *this /= rhs.value;
		}

		constexpr xte::number<T>& operator/=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<T>(xte::div(this->value, rhs));
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator%(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs %= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator%(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs %= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator%=(xte::number<U> rhs) & noexcept {
			return *this %= rhs.value;
		}

		constexpr xte::number<T>& operator%=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<T>(xte::rem(this->value, rhs));
			return *this;
		}

		[[nodiscard]] constexpr xte::number<T> operator~() const noexcept {
			if constexpr (xte::is_float<T>) {
				return -this->value - 1;
			} else {
				return ~this->value;
			}
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator&(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs &= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator&(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs &= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator&=(xte::number<U> rhs) & noexcept {
			return *this &= rhs.value;
		}

		constexpr xte::number<T>& operator&=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<T>(rhs), XTE_LIFT_INFIX(&));
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator|(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs |= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator|(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs |= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator|=(xte::number<U> rhs) & noexcept {
			return *this |= rhs.value;
		}

		constexpr xte::number<T>& operator|=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<T>(rhs), XTE_LIFT_INFIX(|));
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator^(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs ^= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator^(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs ^= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator^=(xte::number<U> rhs) & noexcept {
			return *this ^= rhs.value;
		}

		constexpr xte::number<T>& operator^=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<T>(rhs), XTE_LIFT_INFIX(^));
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator<<(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs <<= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator<<(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs <<= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator<<=(xte::number<U> rhs) & noexcept {
			return *this <<= rhs.value;
		}

		constexpr xte::number<T>& operator<<=(xte::is_arithmetic auto rhs) & noexcept {
			if constexpr (xte::is_float<T>) {
				this->value = xte::make<T>(this->value * xte::pow(static_cast<T>(2), rhs));
			} else {
				if (rhs < 0) {
					return *this >>= xte::abs(rhs);
				}
				this->value = xte::lshift(this->value, xte::make<xte::uz>(rhs));
			}
			return *this;
		}

		template<typename U>
		[[nodiscard]] friend constexpr xte::number<T> operator>>(xte::number<T> lhs, xte::number<U> rhs) noexcept {
			return lhs >>= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<T> operator>>(xte::number<T> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs >>= rhs;
		}

		template<typename U>
		constexpr xte::number<T>& operator>>=(xte::number<U> rhs) & noexcept {
			return *this >>= rhs.value;
		}

		constexpr xte::number<T>& operator>>=(xte::is_arithmetic auto rhs) & noexcept {
			if constexpr (xte::is_float<T>) {
				this->value = xte::make<T>(this->value / xte::pow(static_cast<T>(2), rhs));
			} else {
				if (rhs < 0) {
					return *this <<= xte::abs(rhs);
				}
				this->value = xte::rshift(this->value, xte::make<xte::uz>(rhs));
			}
			return *this;
		}
	};

	template<typename T>
	number(T) -> number<T>;
}

#endif
