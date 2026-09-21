#ifndef DETAIL_XTE_HEADER_MATH_NUMBER
#	define DETAIL_XTE_HEADER_MATH_NUMBER
#
#	include "../abs.hpp"
#	include "../approx_equal.hpp"
#	include "../arithmetic.hpp"
#	include "../exchange.hpp"
#	include "../make.hpp"
#	include "../math/sign_cast.hpp"
#	include "../math/bitwise.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_same_any.hpp"
#	include "../trait/is_same_any_drop_cvref.hpp"
#	include "../trait/try_signed.hpp"
#	include "../trait/try_unsigned.hpp"
#	include <compare>
#	include <limits>

namespace xte {
	template<xte::is_arithmetic arithmetic_type>
	struct number {
	private:
		constexpr void _bitwise(arithmetic_type rhs, auto func) noexcept {
			if constexpr (xte::is_float<arithmetic_type>) {
				arithmetic_type result = 0;
				arithmetic_type mask = std::numeric_limits<arithmetic_type>::min();
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
		using value_type = arithmetic_type;

		arithmetic_type value;

		template<typename other_type = arithmetic_type>
		[[nodiscard]] explicit(!xte::is_same_any_drop_cvref<other_type, xte::try_unsigned<arithmetic_type>, xte::try_signed<arithmetic_type>>)
		constexpr number(other_type&& x = 0) XTE_CONSTRUCTS(
			(value,(xte::make<arithmetic_type>(XTE_FWD(x))))
		)

		template<typename other_type>
		[[nodiscard]] explicit(!xte::is_same_any<other_type, xte::try_unsigned<arithmetic_type>, xte::try_signed<arithmetic_type>>)
		constexpr operator other_type() const noexcept {
			return xte::make<other_type>(this->value);
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return xte::approx_equal(lhs.value, rhs.value)
				? std::strong_ordering::equal
				: xte::less(lhs, rhs)
					? std::strong_ordering::less
					: std::strong_ordering::greater;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr bool operator==(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return xte::approx_equal(lhs.value, rhs.value);
		}

		[[nodiscard]] constexpr xte::number<arithmetic_type> operator+() const noexcept {
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator+(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs += rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator+(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs += rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator+=(xte::number<other_type> rhs) & noexcept {
			return *this += rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator+=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<arithmetic_type>(xte::add(this->value, rhs));
			return *this;
		}

		constexpr xte::number<arithmetic_type>& operator++() & noexcept {
			return *this += 1;
		}

		[[nodiscard]] constexpr xte::number<arithmetic_type> operator++(int) noexcept {
			return xte::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xte::number<arithmetic_type> operator-() const noexcept {
			return xte::number<arithmetic_type>(-xte::as_unsigned(this->value));
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator-(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs -= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator-(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs -= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator-=(xte::number<other_type> rhs) & noexcept {
			return *this -= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator-=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<arithmetic_type>(xte::sub(this->value, rhs));
			return *this;
		}

		constexpr xte::number<arithmetic_type>& operator--() & noexcept {
			return *this -= 1;
		}

		[[nodiscard]] constexpr xte::number<arithmetic_type> operator--(int) noexcept {
			return xte::exchange(*this, *this - 1);
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator*(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs *= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator*(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs *= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator*=(xte::number<other_type> rhs) & noexcept {
			return *this *= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator*=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<arithmetic_type>(xte::mul(this->value, rhs));
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator/(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs /= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator/(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs /= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator/=(xte::number<other_type> rhs) & noexcept {
			return *this /= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator/=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<arithmetic_type>(xte::div(this->value, rhs));
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator%(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs %= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator%(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs %= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator%=(xte::number<other_type> rhs) & noexcept {
			return *this %= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator%=(xte::is_arithmetic auto rhs) & noexcept {
			this->value = xte::make<arithmetic_type>(xte::rem(this->value, rhs));
			return *this;
		}

		[[nodiscard]] constexpr xte::number<arithmetic_type> operator~() const noexcept {
			if constexpr (xte::is_float<arithmetic_type>) {
				return -this->value - 1;
			} else {
				return ~this->value;
			}
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator&(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs &= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator&(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs &= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator&=(xte::number<other_type> rhs) & noexcept {
			return *this &= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator&=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<arithmetic_type>(rhs), XTE_LIFT_INFIX(&));
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator|(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs |= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator|(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs |= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator|=(xte::number<other_type> rhs) & noexcept {
			return *this |= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator|=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<arithmetic_type>(rhs), XTE_LIFT_INFIX(|));
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator^(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs ^= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator^(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs ^= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator^=(xte::number<other_type> rhs) & noexcept {
			return *this ^= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator^=(xte::is_arithmetic auto rhs) & noexcept {
			this->_bitwise(xte::make<arithmetic_type>(rhs), XTE_LIFT_INFIX(^));
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator<<(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs <<= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator<<(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs <<= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator<<=(xte::number<other_type> rhs) & noexcept {
			return *this <<= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator<<=(xte::is_arithmetic auto rhs) & noexcept {
			if constexpr (xte::is_float<arithmetic_type>) {
				this->value = xte::make<arithmetic_type>(this->value * xte::pow(static_cast<arithmetic_type>(2), rhs));
			} else {
				if (rhs < 0) {
					return *this >>= xte::abs(rhs);
				}
				this->value = xte::lshift(this->value, xte::make<xte::uz>(rhs));
			}
			return *this;
		}

		template<typename other_type>
		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator>>(xte::number<arithmetic_type> lhs, xte::number<other_type> rhs) noexcept {
			return lhs >>= rhs;
		}

		[[nodiscard]] friend constexpr xte::number<arithmetic_type> operator>>(xte::number<arithmetic_type> lhs, xte::is_arithmetic auto rhs) noexcept {
			return lhs >>= rhs;
		}

		template<typename other_type>
		constexpr xte::number<arithmetic_type>& operator>>=(xte::number<other_type> rhs) & noexcept {
			return *this >>= rhs.value;
		}

		constexpr xte::number<arithmetic_type>& operator>>=(xte::is_arithmetic auto rhs) & noexcept {
			if constexpr (xte::is_float<arithmetic_type>) {
				this->value = xte::make<arithmetic_type>(this->value / xte::pow(static_cast<arithmetic_type>(2), rhs));
			} else {
				if (rhs < 0) {
					return *this <<= xte::abs(rhs);
				}
				this->value = xte::rshift(this->value, xte::make<xte::uz>(rhs));
			}
			return *this;
		}
	};

	template<typename arithmetic_type>
	number(arithmetic_type) -> number<arithmetic_type>;
}

#endif
