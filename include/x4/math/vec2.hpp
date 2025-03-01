#pragma once

#include <utility>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	struct vec2 {
		T x;
		T y;

		[[nodiscard]] vec2() = default;

		[[nodiscard]] constexpr vec2(T x, T y) noexcept
		: x(x), y(y) {}

		[[nodiscard]] constexpr x4::vec2<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator+(x4::vec2<T> l, x4::vec2<T> r) noexcept {
			return x4::vec2<T>(l.x + r.x, l.y + r.y);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator+(x4::vec2<T> l, T r) noexcept {
			return l + x4::vec2<T>(r, r);
		}

		constexpr x4::vec2<T>& operator+=(x4::vec2<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr x4::vec2<T>& operator+=(T r) noexcept {
			return *this = *this + r;
		}

		constexpr x4::vec2<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr x4::vec2<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr x4::vec2<T> operator-() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator-(x4::vec2<T> l, x4::vec2<T> r) noexcept {
			return x4::vec2<T>(l.x - r.x, l.y - r.y);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator-(x4::vec2<T> l, T r) noexcept {
			return l - x4::vec2<T>(r, r);
		}

		constexpr x4::vec2<T>& operator-=(x4::vec2<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr x4::vec2<T>& operator-=(T r) noexcept {
			return *this = *this - r;
		}

		constexpr x4::vec2<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr x4::vec2<T> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator*(x4::vec2<T> l, x4::vec2<T> r) noexcept {
			return x4::vec2<T>(l.x * r.x, l.y * r.y);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator*(x4::vec2<T> l, T r) noexcept {
			return l * x4::vec2<T>(r, r);
		}

		constexpr x4::vec2<T>& operator*=(x4::vec2<T> r) noexcept {
			return *this = *this * r;
		}

		constexpr x4::vec2<T>& operator*=(T r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator/(x4::vec2<T> l, x4::vec2<T> r) noexcept {
			return x4::vec2<T>(l.x / r.x, l.y / r.y);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator/(x4::vec2<T> l, T r) noexcept {
			return l / x4::vec2<T>(r, r);
		}

		constexpr x4::vec2<T>& operator/=(x4::vec2<T> r) noexcept {
			return *this = *this / r;
		}

		constexpr x4::vec2<T>& operator/=(T r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator%(x4::vec2<T> l, x4::vec2<T> r) noexcept {
			return x4::vec2<T>(l.x % r.x, l.y % r.y);
		}

		[[nodiscard]] friend constexpr x4::vec2<T> operator%(x4::vec2<T> l, T r) noexcept {
			return l % x4::vec2<T>(r, r);
		}

		constexpr x4::vec2<T>& operator%=(x4::vec2<T> r) noexcept {
			return *this = *this % r;
		}

		constexpr x4::vec2<T>& operator%=(T r) noexcept {
			return *this = *this % r;
		}
	};

	template<typename T>
	vec2(T, T) -> vec2<T>;
}
