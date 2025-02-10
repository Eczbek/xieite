#pragma once

#include <cmath>
#include <compare>
#include <concepts>
#include <functional>
#include <limits>
#include "../math/neg.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct num {
	public:
		using type = T;

		T value = 0;

		[[nodiscard]] explicit constexpr operator T() const noexcept {
			return this->value;
		}

		template<xieite::is_arith U>
		[[nodiscard]] explicit constexpr operator xieite::num<U>() const noexcept {
			return xieite::num<U>(static_cast<U>(this->value));
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::num<T> l, xieite::num<T> r) noexcept {
			return l.value <=> r.value;
		}

		[[nodiscard]] friend bool operator==(xieite::num<T>, xieite::num<T>) = default;

		[[nodiscard]] constexpr xieite::num<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator+(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>(l.value + r.value);
		}

		constexpr xieite::num<T>& operator+=(xieite::num<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr xieite::num<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::num<T> operator++(int) noexcept {
			return xieite::num<T>(this->value++);
		}

		[[nodiscard]] constexpr xieite::num<T> operator-() const noexcept {
			return xieite::num<T>(-this->value);
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator-(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>(l.value - r.value);
		}

		constexpr xieite::num<T>& operator-=(xieite::num<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr xieite::num<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::num<T> operator--(int) noexcept {
			return xieite::num<T>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator*(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>(l.value * r.value);
		}

		constexpr xieite::num<T>& operator*=(xieite::num<T> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator/(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>(l.value / r.value);
		}

		constexpr xieite::num<T>& operator/=(xieite::num<T> r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator%(xieite::num<T> l, xieite::num<T> r) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(std::fmod(l.value, r.value));
			} else {
				return xieite::num<T>(l.value % r.value);
			}
		}

		constexpr xieite::num<T>& operator%=(xieite::num<T> r) noexcept {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr xieite::num<T> operator~() const noexcept {
			if constexpr (std::floating_point<T>) {
				return -*this - 1;
			} else {
				return xieite::num<T>(~this->value);
			}
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator&(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>::bit_op(l, r, std::bit_and());
		}

		constexpr xieite::num<T>& operator&=(xieite::num<T> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator|(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>::bit_op(l, r, std::bit_or());
		}

		constexpr xieite::num<T>& operator|=(xieite::num<T> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator^(xieite::num<T> l, xieite::num<T> r) noexcept {
			return xieite::num<T>::bit_op(l, r, std::bit_xor());
		}

		constexpr xieite::num<T>& operator^=(xieite::num<T> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator<<(xieite::num<T> l, T r) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(l.value * std::pow(2, r));
			} else if (xieite::neg(r)) {
				return l >> -r;
			} else {
				return xieite::num<T>(l.value << r);
			}
		}

		constexpr xieite::num<T>& operator<<=(T r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator>>(xieite::num<T> l, T r) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(l.value / std::pow(2, r));
			} else if (xieite::neg(r)) {
				return l << -r;
			} else {
				return xieite::num<T>(l.value >> r);
			}
		}

		constexpr xieite::num<T>& operator>>=(T r) noexcept {
			return *this = *this >> r;
		}

	private:
		[[nodiscard]] static constexpr xieite::num<T> bit_op(xieite::num<T> l, xieite::num<T> r, auto fn) noexcept {
			if constexpr (std::floating_point<T>) {
				T result = 0;
				T mask = std::numeric_limits<T>::min();
				while (mask <= std::numeric_limits<T>::max()) {
					if (fn(std::fmod(l.value, mask * 2) >= mask, std::fmod(r.value, mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				return xieite::num<T>(result);
			} else {
				return xieite::num<T>(fn(l.value, r.value));
			}
		}
	};
}
