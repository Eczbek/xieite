#pragma once

#include <cmath>
#include <type_traits>
#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

namespace XIEITE_DETAIL {
	template<auto functor>
	struct Infix {
		template<typename Type>
		struct Intermediate {
			Type&& left;

			[[nodiscard]] constexpr decltype(auto) operator->*(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator*(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator&(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator^(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator|(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator&&(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] constexpr decltype(auto) operator||(Type&& right) const noexcept {
				return functor(XIEITE_FORWARD(this->left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] friend constexpr decltype(auto) operator+=(Type&& right, const Intermediate self) noexcept {
				return functor(XIEITE_FORWARD(self.left), XIEITE_FORWARD(right));
			}

			[[nodiscard]] friend constexpr decltype(auto) operator*=(Type&& right, const Intermediate self) noexcept {
				return functor(XIEITE_FORWARD(self.left), XIEITE_FORWARD(right));
			}
		};

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator->*(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator*(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator&(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator^(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator|(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator&&(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		template<typename Type>
		[[nodiscard]] friend constexpr Infix::Intermediate<Type> operator||(Type&& left, Infix) noexcept {
			return Infix::Intermediate<Type>(XIEITE_FORWARD(left));
		}

		[[nodiscard]] constexpr auto operator+=(auto&& left) const noexcept {
			return Infix::Intermediate<decltype(left)>(XIEITE_FORWARD(left));
		}
	};

	template<auto functor>
	struct Prefix {
		[[nodiscard]] constexpr decltype(auto) operator->*(auto&& right) noexcept {
			return functor(XIEITE_FORWARD(right));
		}
	};

	struct Negate {
		[[nodiscard]] constexpr auto operator,(auto&& value, Negate) XIEITE_ARROW(static_cast<bool>(!XIEITE_FORWARD(value)))
	};

	struct LoopState {
		struct Chainable {
			constexpr void operator+() const noexcept {}

			/* discardable */ friend constexpr auto&& operator+(auto&& value, Chainable) noexcept {
				return XIEITE_FORWARD(value);
			}
		};

		int flag = 2;
		bool broke = false;

		[[nodiscard]] constexpr auto operator*() const noexcept {
			this->broke = true;
			return LoopState::Chainable();
		}
	};
}

#define nand && XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return !XIEITE_FORWARD(x) || !XIEITE_FORWARD(y); }>() &&
#define nor || XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return !XIEITE_FORWARD(x) && !XIEITE_FORWARD(y); }>() ||
#define xnor ^ XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return XIEITE_FORWARD(x) == XIEITE_FORWARD(y); }>() ^
#define not_eq XIEITE_DETAIL::Prefix<[](auto& x) { return x = !x; }>() ->*
#define nand_eq = XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = !x || !XIEITE_FORWARD(y); }>() +=
#define nor_eq = XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = !x && !XIEITE_FORWARD(y); }>() +=
#define xnor_eq = XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x == XIEITE_FORWARD(y); }>() +=
#define bitnand & XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return ~XIEITE_FORWARD(x) | ~XIEITE_FORWARD(y); }>() &
#define bitnor | XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return ~XIEITE_FORWARD(x) & ~XIEITE_FORWARD(y); }>() |
#define bitxnor ^ XIEITE_DETAIL::Infix<[](auto&& x, auto&& y) { return ~(~XIEITE_FORWARD(x) ^ ~XIEITE_FORWARD(y)); }>() ^
#define compl_eq XIEITE_DETAIL::Prefix<[](auto& x) { return x = ~x; }>() ->*
#define bitand_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x & XIEITE_FORWARD(y); }>() +=
#define bitnand_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x bitnand XIEITE_FORWARD(y); }>() +=
#define bitor_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x | XIEITE_FORWARD(y); }>() +=
#define bitnor_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x bitnor XIEITE_FORWARD(y); }>() +=
#define bitxor_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x ^ XIEITE_FORWARD(y); }>() +=
#define bitxnor_eq += XIEITE_DETAIL::Infix<[](auto& x, auto&& y) { return x = x bitxnor XIEITE_FORWARD(y); }>() +=

#define ifn(...) if (__VA_ARGS__, XIEITE_DETAIL::Negate())
#define elif else if
#define elifn(...) else ifn
#define if_try(...) \
	if (([&] { \
		try { \
			__VA_ARGS__; \
			return true; \
		} catch (...) { \
			return false; \
		} \
	})())
#define ifn_try(...) if_try(__VA_ARGS__, XIEITE_DETAIL::Negate())
#define elif_try else if_try
#define elifn_try else ifn_try
#define if_requires(...) if constexpr (requires { __VA_ARGS__; })
#define ifn_requires(...) if_requires(__VA_ARGS__) {} elif(true)
#define elif_requires else if_requires
#define elifn_requires else ifn_requires
#define if_for(...) \
	for (XIEITE_DETAIL::LoopState XIEITE_DETAIL_LOOP_STATE; XIEITE_DETAIL_LOOP_STATE.flag && !XIEITE_DETAIL_LOOP_STATE.broke; --XIEITE_DETAIL_LOOP_STATE.flag) \
		if ((XIEITE_DETAIL_LOOP_STATE.flag == 2) && !XIEITE_DETAIL_LOOP_STATE.broke) \
			for (__VA_ARGS__ + *XIEITE_DETAIL_LOOP_STATE) \
				if ((XIEITE_DETAIL_LOOP_STATE.broke = false)); \
				else
#define elif_for else if_for
#define if_while(...) if_for(; __VA_ARGS__;)
#define elif_while else if_while

#define of : // Range-based `for` loop, Underlying type of enumeration
#define extends : // Inheritance
#define inits : // Member initializer list

#define lest break; case
#define yet break; default
#define perchance continue; case
#define otherwise continue; default

// Loop macros originally stolen from m1lkweed (https://gist.github.com/m1lkweed/3be672402c43ac5697f1e29bcb79e004)
