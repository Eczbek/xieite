#ifndef DETAIL_XIEITE_HEADER_MATH_NUM
#	define DETAIL_XIEITE_HEADER_MATH_NUM
#
#	include <cmath>
#	include <compare>
#	include <concepts>
#	include <functional>
#	include <limits>
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	struct number {
	public:
		using type = Arith;

		Arith value = 0;

		[[nodiscard]] explicit constexpr operator Arith() const noexcept {
			return this->value;
		}

		template<xieite::is_arith OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::number<OtherArith>() const noexcept {
			return xieite::number<OtherArith>(static_cast<OtherArith>(this->value));
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return lhs.value <=> rhs.value;
		}

		[[nodiscard]] friend bool operator==(xieite::number<Arith>, xieite::number<Arith>) = default;

		[[nodiscard]] constexpr xieite::number<Arith> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator+(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>(lhs.value + rhs.value);
		}

		constexpr xieite::number<Arith>& operator+=(xieite::number<Arith> rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::number<Arith>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::number<Arith> operator++(int) noexcept {
			return xieite::number<Arith>(this->value++);
		}

		[[nodiscard]] constexpr xieite::number<Arith> operator-() const noexcept {
			return xieite::number<Arith>(-this->value);
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator-(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>(lhs.value - rhs.value);
		}

		constexpr xieite::number<Arith>& operator-=(xieite::number<Arith> rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::number<Arith>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::number<Arith> operator--(int) noexcept {
			return xieite::number<Arith>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator*(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>(lhs.value * rhs.value);
		}

		constexpr xieite::number<Arith>& operator*=(xieite::number<Arith> rhs) noexcept {
			return *this = *this * rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator/(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>(lhs.value / rhs.value);
		}

		constexpr xieite::number<Arith>& operator/=(xieite::number<Arith> rhs) noexcept {
			return *this = *this / rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator%(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			if constexpr (std::floating_point<Arith>) {
				return xieite::number<Arith>(std::fmod(lhs.value, rhs.value));
			} else {
				return xieite::number<Arith>(lhs.value % rhs.value);
			}
		}

		constexpr xieite::number<Arith>& operator%=(xieite::number<Arith> rhs) noexcept {
			return *this = *this % rhs;
		}

		[[nodiscard]] constexpr xieite::number<Arith> operator~() const noexcept {
			if constexpr (std::floating_point<Arith>) {
				return -*this - 1;
			} else {
				return xieite::number<Arith>(~this->value);
			}
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator&(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>::bit_op(lhs, rhs, std::bit_and());
		}

		constexpr xieite::number<Arith>& operator&=(xieite::number<Arith> rhs) noexcept {
			return *this = *this & rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator|(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>::bit_op(lhs, rhs, std::bit_or());
		}

		constexpr xieite::number<Arith>& operator|=(xieite::number<Arith> rhs) noexcept {
			return *this = *this | rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator^(xieite::number<Arith> lhs, xieite::number<Arith> rhs) noexcept {
			return xieite::number<Arith>::bit_op(lhs, rhs, std::bit_xor());
		}

		constexpr xieite::number<Arith>& operator^=(xieite::number<Arith> rhs) noexcept {
			return *this = *this ^ rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator<<(xieite::number<Arith> lhs, Arith rhs) noexcept {
			if constexpr (std::floating_point<Arith>) {
				return xieite::number<Arith>(lhs.value * std::pow(2, rhs));
			} else if (xieite::neg(rhs)) {
				return lhs >> -rhs;
			} else {
				return xieite::number<Arith>(lhs.value << rhs);
			}
		}

		constexpr xieite::number<Arith>& operator<<=(Arith rhs) noexcept {
			return *this = *this << rhs;
		}

		[[nodiscard]] friend constexpr xieite::number<Arith> operator>>(xieite::number<Arith> lhs, Arith rhs) noexcept {
			if constexpr (std::floating_point<Arith>) {
				return xieite::number<Arith>(lhs.value / std::pow(2, rhs));
			} else if (xieite::neg(rhs)) {
				return lhs << -rhs;
			} else {
				return xieite::number<Arith>(lhs.value >> rhs);
			}
		}

		constexpr xieite::number<Arith>& operator>>=(Arith rhs) noexcept {
			return *this = *this >> rhs;
		}

	private:
		[[nodiscard]] static constexpr xieite::number<Arith> bit_op(xieite::number<Arith> lhs, xieite::number<Arith> rhs, auto fn) noexcept {
			if constexpr (std::floating_point<Arith>) {
				Arith result = 0;
				Arith mask = std::numeric_limits<Arith>::min();
				while (mask <= std::numeric_limits<Arith>::max()) {
					if (fn(std::fmod(lhs.value, mask * 2) >= mask, std::fmod(rhs.value, mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				return xieite::number<Arith>(result);
			} else {
				return xieite::number<Arith>(fn(lhs.value, rhs.value));
			}
		}
	};
}

#endif
