#pragma once

#include <cmath>
#include <compare>
#include <concepts>
#include <functional>
#include <limits>
#include "../math/neg.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	struct n {
	public:
		using type = T;

		T value = 0;

		[[nodiscard]] explicit constexpr operator T() const noexcept {
			return this->value;
		}

		template<x4::isarith U>
		[[nodiscard]] explicit constexpr operator x4::n<U>() const noexcept {
			return x4::n<U>(static_cast<U>(this->value));
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(x4::n<T> l, x4::n<T> r) noexcept {
			return l.value <=> r.value;
		}

		[[nodiscard]] friend bool operator==(x4::n<T>, x4::n<T>) = default;

		[[nodiscard]] constexpr x4::n<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator+(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>(l.value + r.value);
		}

		constexpr x4::n<T>& operator+=(x4::n<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr x4::n<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr x4::n<T> operator++(int) noexcept {
			return x4::n<T>(this->value++);
		}

		[[nodiscard]] constexpr x4::n<T> operator-() const noexcept {
			return x4::n<T>(-this->value);
		}

		[[nodiscard]] friend constexpr x4::n<T> operator-(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>(l.value - r.value);
		}

		constexpr x4::n<T>& operator-=(x4::n<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr x4::n<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr x4::n<T> operator--(int) noexcept {
			return x4::n<T>(this->value--);
		}

		[[nodiscard]] friend constexpr x4::n<T> operator*(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>(l.value * r.value);
		}

		constexpr x4::n<T>& operator*=(x4::n<T> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator/(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>(l.value / r.value);
		}

		constexpr x4::n<T>& operator/=(x4::n<T> r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator%(x4::n<T> l, x4::n<T> r) noexcept {
			if constexpr (std::floating_point<T>) {
				return x4::n<T>(std::fmod(l.value, r.value));
			} else {
				return x4::n<T>(l.value % r.value);
			}
		}

		constexpr x4::n<T>& operator%=(x4::n<T> r) noexcept {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr x4::n<T> operator~() const noexcept {
			if constexpr (std::floating_point<T>) {
				return -*this - 1;
			} else {
				return x4::n<T>(~this->value);
			}
		}

		[[nodiscard]] friend constexpr x4::n<T> operator&(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>::bit_op(l, r, std::bit_and());
		}

		constexpr x4::n<T>& operator&=(x4::n<T> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator|(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>::bit_op(l, r, std::bit_or());
		}

		constexpr x4::n<T>& operator|=(x4::n<T> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator^(x4::n<T> l, x4::n<T> r) noexcept {
			return x4::n<T>::bit_op(l, r, std::bit_xor());
		}

		constexpr x4::n<T>& operator^=(x4::n<T> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator<<(x4::n<T> l, T r) noexcept {
			if constexpr (std::floating_point<T>) {
				return x4::n<T>(l.value * std::pow(2, r));
			} else if (x4::neg(r)) {
				return l >> -r;
			} else {
				return x4::n<T>(l.value << r);
			}
		}

		constexpr x4::n<T>& operator<<=(T r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr x4::n<T> operator>>(x4::n<T> l, T r) noexcept {
			if constexpr (std::floating_point<T>) {
				return x4::n<T>(l.value / std::pow(2, r));
			} else if (x4::neg(r)) {
				return l << -r;
			} else {
				return x4::n<T>(l.value >> r);
			}
		}

		constexpr x4::n<T>& operator>>=(T r) noexcept {
			return *this = *this >> r;
		}

	private:
		[[nodiscard]] static constexpr x4::n<T> bit_op(x4::n<T> l, x4::n<T> r, auto fn) noexcept {
			if constexpr (std::floating_point<T>) {
				T result = 0;
				T mask = std::numeric_limits<T>::min();
				while (mask <= std::numeric_limits<T>::max()) {
					if (fn(std::fmod(l.value, mask * 2) >= mask, std::fmod(r.value, mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				return x4::n<T>(result);
			} else {
				return x4::n<T>(fn(l.value, r.value));
			}
		}
	};
}
