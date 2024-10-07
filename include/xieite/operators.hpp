#pragma once

template<auto functor>
struct XIEITE_DETAIL_OPERATOR {
	template<typename Type>
	struct Intermediate {
		Type left;

		[[nodiscard]] constexpr Type operator&&(const Type right) const noexcept {
			return static_cast<Type>(functor(this->left, right));
		}

		[[nodiscard]] constexpr Type operator||(const Type right) const noexcept {
			return static_cast<Type>(functor(this->left, right));
		}

		[[nodiscard]] constexpr Type operator&(const Type right) const noexcept {
			return static_cast<Type>(functor(this->left, right));
		}

		[[nodiscard]] constexpr Type operator|(const Type right) const noexcept {
			return static_cast<Type>(functor(this->left, right));
		}

		[[nodiscard]] constexpr Type operator^(const Type right) const noexcept {
			return static_cast<Type>(functor(this->left, right));
		}

		friend constexpr Type operator&=(const Type right, const Intermediate self) noexcept {
			return static_cast<Type>(functor(self.left, right));
		}

		friend constexpr Type operator|=(const Type right, const Intermediate self) noexcept {
			return static_cast<Type>(functor(self.left, right));
		}

		friend constexpr Type operator^=(const Type right, const Intermediate self) noexcept {
			return static_cast<Type>(functor(self.left, right));
		}
	};

	template<typename Type>
	[[nodiscard]] friend constexpr auto operator&&(const Type left, XIEITE_DETAIL_OPERATOR) noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] friend constexpr auto operator||(const Type left, XIEITE_DETAIL_OPERATOR) noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] friend constexpr auto operator&(const Type left, XIEITE_DETAIL_OPERATOR) noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] friend constexpr auto operator|(const Type left, XIEITE_DETAIL_OPERATOR) noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] friend constexpr auto operator^(const Type left, XIEITE_DETAIL_OPERATOR) noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] constexpr auto operator&=(const Type left) const noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] constexpr auto operator|=(const Type left) const noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}

	template<typename Type>
	[[nodiscard]] constexpr auto operator^=(const Type left) const noexcept {
		return XIEITE_DETAIL_OPERATOR::Intermediate<Type>(left);
	}
};

#define nand && XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return !x || !y; }>() &&
#define nor || XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return !x && !y; }>() ||
#define xnor ^ XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return x == y; }>() ^
#define nand_eq &= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = !x || !y; }>() &=
#define nor_eq |= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = !x && !y; }>() |=
#define xnor_eq ^= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = x == y; }>() ^=
#define bitnand & XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return ~x | ~y; }>() &
#define bitnor | XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return ~x & ~y; }>() |
#define bitxor ^ XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return x ^ y; }>() ^
#define bitxnor ^ XIEITE_DETAIL_OPERATOR<[](auto x, auto y) { return ~(~x ^ ~y); }>() ^
#define bitand_eq &= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = x & y; }>() &=
#define bitnand_eq &= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = ~x | ~y; }>() &=
#define bitor_eq |= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = x | y; }>() |=
#define bitnor_eq |= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = ~x & ~y; }>() |=
#define bitxor_eq ^= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = x ^ y; }>() ^=
#define bitxnor_eq ^= XIEITE_DETAIL_OPERATOR<[](auto& x, auto y) { return x = ~(~x ^ ~y); }>() ^=
