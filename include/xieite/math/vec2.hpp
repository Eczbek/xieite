#ifndef DETAIL_XIEITE_HEADER_MATH_VECTOR2
#	define DETAIL_XIEITE_HEADER_MATH_VECTOR2
#
#	include <utility>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	struct vec2 {
		Arith x;
		Arith y;

		[[nodiscard]] constexpr vec2() noexcept
		: x(0), y(0) {}

		[[nodiscard]] constexpr vec2(Arith x, Arith y) noexcept
		: x(x), y(y) {}

		[[nodiscard]] friend bool operator==(const xieite::vec2<Arith>&, const xieite::vec2<Arith>&) = default;

		[[nodiscard]] constexpr xieite::vec2<Arith> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator+(xieite::vec2<Arith> lhs, xieite::vec2<Arith> rhs) noexcept {
			return xieite::vec2<Arith>(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator+(xieite::vec2<Arith> lhs, Arith rhs) noexcept {
			return lhs + xieite::vec2<Arith>(rhs, rhs);
		}

		constexpr xieite::vec2<Arith>& operator+=(xieite::vec2<Arith> rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::vec2<Arith>& operator+=(Arith rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::vec2<Arith>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::vec2<Arith> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::vec2<Arith> operator-() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator-(xieite::vec2<Arith> lhs, xieite::vec2<Arith> rhs) noexcept {
			return xieite::vec2<Arith>(lhs.x - rhs.x, lhs.y - rhs.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator-(xieite::vec2<Arith> lhs, Arith rhs) noexcept {
			return lhs - xieite::vec2<Arith>(rhs, rhs);
		}

		constexpr xieite::vec2<Arith>& operator-=(xieite::vec2<Arith> rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::vec2<Arith>& operator-=(Arith rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::vec2<Arith>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::vec2<Arith> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator*(xieite::vec2<Arith> lhs, xieite::vec2<Arith> rhs) noexcept {
			return xieite::vec2<Arith>(lhs.x * rhs.x, lhs.y * rhs.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator*(xieite::vec2<Arith> lhs, Arith rhs) noexcept {
			return lhs * xieite::vec2<Arith>(rhs, rhs);
		}

		constexpr xieite::vec2<Arith>& operator*=(xieite::vec2<Arith> rhs) noexcept {
			return *this = *this * rhs;
		}

		constexpr xieite::vec2<Arith>& operator*=(Arith rhs) noexcept {
			return *this = *this * rhs;
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator/(xieite::vec2<Arith> lhs, xieite::vec2<Arith> rhs) noexcept {
			return xieite::vec2<Arith>(lhs.x / rhs.x, lhs.y / rhs.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator/(xieite::vec2<Arith> lhs, Arith rhs) noexcept {
			return lhs / xieite::vec2<Arith>(rhs, rhs);
		}

		constexpr xieite::vec2<Arith>& operator/=(xieite::vec2<Arith> rhs) noexcept {
			return *this = *this / rhs;
		}

		constexpr xieite::vec2<Arith>& operator/=(Arith rhs) noexcept {
			return *this = *this / rhs;
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator%(xieite::vec2<Arith> lhs, xieite::vec2<Arith> rhs) noexcept {
			return xieite::vec2<Arith>(lhs.x % rhs.x, lhs.y % rhs.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<Arith> operator%(xieite::vec2<Arith> lhs, Arith rhs) noexcept {
			return lhs % xieite::vec2<Arith>(rhs, rhs);
		}

		constexpr xieite::vec2<Arith>& operator%=(xieite::vec2<Arith> rhs) noexcept {
			return *this = *this % rhs;
		}

		constexpr xieite::vec2<Arith>& operator%=(Arith rhs) noexcept {
			return *this = *this % rhs;
		}
	};

	template<typename Arith>
	vec2(Arith, Arith) -> vec2<Arith>;
}

#endif
