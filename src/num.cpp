export module xieite:num;

import std;
import :is_arith;
import :neg;

export namespace xieite {
	template<xieite::is_arith T>
	struct num : std::type_identity<T> {
	public:
		T value;

		explicit(false) constexpr xieite::num<T>(T value = 0) noexcept
		: value(value) {}

		explicit constexpr operator T() const noexcept {
			return this->value;
		}

		template<xieite::is_arith U>
		[[nodiscard]] explicit constexpr operator xieite::num<U>() const noexcept {
			return xieite::num<U>(static_cast<U>(this->value));
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::num<T> left, xieite::num<T> right) noexcept {
			return left.value <=> right.value;
		}

		[[nodiscard]] friend bool operator==(xieite::num<T>, xieite::num<T>) = default;

		[[nodiscard]] constexpr xieite::num<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator+(xieite::num<T> augend, xieite::num<T> addend) noexcept {
			return xieite::num<T>(augend.value + addend.value);
		}

		constexpr xieite::num<T>& operator+=(xieite::num<T> addend) noexcept {
			return *this = *this + addend;
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

		[[nodiscard]] friend constexpr xieite::num<T> operator-(xieite::num<T> minuend, xieite::num<T> subtrahend) noexcept {
			return xieite::num<T>(minuend.value - subtrahend.value);
		}

		constexpr xieite::num<T>& operator-=(xieite::num<T> addend) noexcept {
			return *this = *this - addend;
		}

		constexpr xieite::num<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::num<T> operator--(int) noexcept {
			return xieite::num<T>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator*(xieite::num<T> augend, xieite::num<T> addend) noexcept {
			return xieite::num<T>(augend.value * addend.value);
		}

		constexpr xieite::num<T>& operator*=(xieite::num<T> addend) noexcept {
			return *this = *this * addend;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator/(xieite::num<T> augend, xieite::num<T> addend) noexcept {
			return xieite::num<T>(augend.value / addend.value);
		}

		constexpr xieite::num<T>& operator/=(xieite::num<T> addend) noexcept {
			return *this = *this / addend;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator%(xieite::num<T> augend, xieite::num<T> addend) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(std::fmod(augend.value, addend.value));
			} else {
				return xieite::num<T>(augend.value % addend.value);
			}
		}

		constexpr xieite::num<T>& operator%=(xieite::num<T> addend) noexcept {
			return *this = *this % addend;
		}

		[[nodiscard]] constexpr xieite::num<T> operator~() const noexcept {
			if constexpr (std::floating_point<T>) {
				return -*this - 1;
			} else {
				return xieite::num<T>(~this->value);
			}
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator&(xieite::num<T> left, xieite::num<T> right) noexcept {
			return xieite::num<T>::bit_op(left, right, std::bit_and());
		}

		constexpr xieite::num<T>& operator&=(xieite::num<T> right) noexcept {
			return *this = *this & right;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator|(xieite::num<T> left, xieite::num<T> right) noexcept {
			return xieite::num<T>::bit_op(left, right, std::bit_or());
		}

		constexpr xieite::num<T>& operator|=(xieite::num<T> right) noexcept {
			return *this = *this | right;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator^(xieite::num<T> left, xieite::num<T> right) noexcept {
			return xieite::num<T>::bit_op(left, right, std::bit_xor());
		}

		constexpr xieite::num<T>& operator^=(xieite::num<T> right) noexcept {
			return *this = *this ^ right;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator<<(xieite::num<T> left, T right) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(left.value * std::pow(2, right));
			} else if (xieite::neg(right)) {
				return left >> -right;
			} else {
				return xieite::num<T>(left.value << right);
			}
		}

		constexpr xieite::num<T>& operator<<=(T right) noexcept {
			return *this = *this << right;
		}

		[[nodiscard]] friend constexpr xieite::num<T> operator>>(xieite::num<T> left, T right) noexcept {
			if constexpr (std::floating_point<T>) {
				return xieite::num<T>(left.value / std::pow(2, right));
			} else if (xieite::neg(right)) {
				return left << -right;
			} else {
				return xieite::num<T>(left.value >> right);
			}
		}

		constexpr xieite::num<T>& operator>>=(T right) noexcept {
			return *this = *this >> right;
		}

	private:
		[[nodiscard]] static constexpr xieite::num<T> bit_op(xieite::num<T> left, xieite::num<T> right, auto fn) noexcept {
			if constexpr (std::floating_point<T>) {
				T result = 0;
				T mask = std::numeric_limits<T>::min();
				while (mask <= std::numeric_limits<T>::max()) {
					if (fn(std::fmod(left.value, mask * 2) >= mask, std::fmod(right.value, mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				return xieite::num<T>(result);
			} else {
				return xieite::num<T>(fn(left.value, right.value));
			}
		}
	};
}
