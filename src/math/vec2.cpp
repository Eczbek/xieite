export module xieite:vec2;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	struct vec2 {
		T x = 0;
		T y = 0;

		[[nodiscard]] vec2() = default;

		[[nodiscard]] constexpr vec2(T x, T y) noexcept
		: x(x), y(y) {}

		[[nodiscard]] constexpr xieite::vec2<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator+(xieite::vec2<T> left, xieite::vec2<T> right) noexcept {
			return xieite::vec2<T>(left.x + right.x, left.y + right.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator+(xieite::vec2<T> left, T right) noexcept {
			return left + xieite::vec2<T>(right, right);
		}

		constexpr xieite::vec2<T>& operator+=(xieite::vec2<T> right) noexcept {
			return *this = *this + right;
		}

		constexpr xieite::vec2<T>& operator+=(T right) noexcept {
			return *this = *this + right;
		}

		constexpr xieite::vec2<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::vec2<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::vec2<T> operator-() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator-(xieite::vec2<T> left, xieite::vec2<T> right) noexcept {
			return xieite::vec2<T>(left.x - right.x, left.y - right.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator-(xieite::vec2<T> left, T right) noexcept {
			return left - xieite::vec2<T>(right, right);
		}

		constexpr xieite::vec2<T>& operator-=(xieite::vec2<T> right) noexcept {
			return *this = *this - right;
		}

		constexpr xieite::vec2<T>& operator-=(T right) noexcept {
			return *this = *this - right;
		}

		constexpr xieite::vec2<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::vec2<T> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator*(xieite::vec2<T> left, xieite::vec2<T> right) noexcept {
			return xieite::vec2<T>(left.x * right.x, left.y * right.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator*(xieite::vec2<T> left, T right) noexcept {
			return left * xieite::vec2<T>(right, right);
		}

		constexpr xieite::vec2<T>& operator*=(xieite::vec2<T> right) noexcept {
			return *this = *this * right;
		}

		constexpr xieite::vec2<T>& operator*=(T right) noexcept {
			return *this = *this * right;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator/(xieite::vec2<T> left, xieite::vec2<T> right) noexcept {
			return xieite::vec2<T>(left.x / right.x, left.y / right.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator/(xieite::vec2<T> left, T right) noexcept {
			return left / xieite::vec2<T>(right, right);
		}

		constexpr xieite::vec2<T>& operator/=(xieite::vec2<T> right) noexcept {
			return *this = *this / right;
		}

		constexpr xieite::vec2<T>& operator/=(T right) noexcept {
			return *this = *this / right;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator%(xieite::vec2<T> left, xieite::vec2<T> right) noexcept {
			return xieite::vec2<T>(left.x % right.x, left.y % right.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator%(xieite::vec2<T> left, T right) noexcept {
			return left % xieite::vec2<T>(right, right);
		}

		constexpr xieite::vec2<T>& operator%=(xieite::vec2<T> right) noexcept {
			return *this = *this % right;
		}

		constexpr xieite::vec2<T>& operator%=(T right) noexcept {
			return *this = *this % right;
		}
	};

	template<typename T>
	vec2(T, T) -> vec2<T>;
}
