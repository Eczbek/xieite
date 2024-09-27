export module xieite:math.Number;

import std;
import :concepts.Arithmetic;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Number
	: std::type_identity<Arithmetic> {
	public:
		Arithmetic value;

		explicit(false) constexpr Number(const Arithmetic value = 0) noexcept
		: value(value) {}

		explicit constexpr operator Arithmetic() const noexcept {
			return this->value;
		}

		template<xieite::concepts::Arithmetic OtherArithmetic>
		[[nodiscard]] explicit constexpr operator Number<OtherArithmetic>() const noexcept {
			return Number<OtherArithmetic>(static_cast<OtherArithmetic>(this->value));
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const Number left, const Number right) noexcept {
			return left.value <=> right.value;
		}

		[[nodiscard]] friend bool operator==(Number, Number) = default;

		[[nodiscard]] constexpr Number operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr Number operator+(const Number augend, const Number addend) noexcept {
			return Number(augend.value + addend.value);
		}

		constexpr Number& operator+=(const Number addend) noexcept {
			return *this = *this + addend;
		}

		constexpr Number& operator++() noexcept {
			return *this += 1;
		}

		constexpr Number operator++(int) noexcept {
			return Number(this->value++);
		}

		[[nodiscard]] constexpr Number operator-() const noexcept {
			return Number(-this->value);
		}

		[[nodiscard]] friend constexpr Number operator-(const Number minuend, const Number subtrahend) noexcept {
			return Number(minuend.value - subtrahend.value);
		}

		constexpr Number& operator-=(const Number addend) noexcept {
			return *this = *this - addend;
		}

		constexpr Number& operator--() noexcept {
			return *this -= 1;
		}

		constexpr Number operator--(int) noexcept {
			return Number(this->value--);
		}

		[[nodiscard]] friend constexpr Number operator*(const Number augend, const Number addend) noexcept {
			return Number(augend.value * addend.value);
		}

		constexpr Number& operator*=(const Number addend) noexcept {
			return *this = *this * addend;
		}

		[[nodiscard]] friend constexpr Number operator/(const Number augend, const Number addend) noexcept {
			return Number(augend.value / addend.value);
		}

		constexpr Number& operator/=(const Number addend) noexcept {
			return *this = *this / addend;
		}

		[[nodiscard]] friend constexpr Number operator%(const Number augend, const Number addend) noexcept {
			if constexpr (std::floating_point<Arithmetic>) {
				return Number(std::fmod(augend.value, addend.value));
			} else {
				return Number(augend.value % addend.value);
			}
		}

		constexpr Number& operator%=(const Number addend) noexcept {
			return *this = *this % addend;
		}

		[[nodiscard]] constexpr Number operator~() const noexcept {
			if constexpr (std::floating_point<Arithmetic>) {
				return -*this - 1;
			} else {
				return Number(~this->value);
			}
		}

		[[nodiscard]] friend constexpr Number operator&(const Number left, const Number right) noexcept {
			return Number::bitwiseOperation(left, right, std::bit_and());
		}

		constexpr Number& operator&=(const Number right) noexcept {
			return *this = *this & right;
		}

		[[nodiscard]] friend constexpr Number operator|(const Number left, const Number right) noexcept {
			return Number::bitwiseOperation(left, right, std::bit_or());
		}

		constexpr Number& operator|=(const Number right) noexcept {
			return *this = *this | right;
		}

		[[nodiscard]] friend constexpr Number operator^(const Number left, const Number right) noexcept {
			return Number::bitwiseOperation(left, right, std::bit_xor());
		}

		constexpr Number& operator^=(const Number right) noexcept {
			return *this = *this ^ right;
		}

		[[nodiscard]] friend constexpr Number operator<<(const Number left, const Arithmetic right) noexcept {
			if constexpr (std::floating_point<Arithmetic>) {
				return Number(left.value * std::pow(2, right));
			} else if (xieite::math::isNegative(right)) {
				return left >> -right;
			} else {
				return Number(left.value << right);
			}
		}

		constexpr Number& operator<<=(const Arithmetic right) noexcept {
			return *this = *this << right;
		}

		[[nodiscard]] friend constexpr Number operator>>(const Number left, const Arithmetic right) noexcept {
			if constexpr (std::floating_point<Arithmetic>) {
				return Number(left.value / std::pow(2, right));
			} else if (xieite::math::isNegative(right)) {
				return left << -right;
			} else {
				return Number(left.value >> right);
			}
		}

		constexpr Number& operator>>=(const Arithmetic right) noexcept {
			return *this = *this >> right;
		}

	private:
		[[nodiscard]] static constexpr Number bitwiseOperation(const Number left, const Number right, const auto callback) noexcept {
			if constexpr (std::floating_point<Arithmetic>) {
				Arithmetic result = 0;
				Arithmetic mask = std::numeric_limits<Arithmetic>::min();
				while (mask <= std::numeric_limits<Arithmetic>::max()) {
					if (callback(std::fmod(left.value, mask * 2) >= mask, std::fmod(right.value, mask * 2) >= mask)) {
						result += mask;
					}
					mask *= 2;
				}
				return Number(result);
			} else {
				return Number(callback(left.value, right.value));
			}
		}
	};
}
