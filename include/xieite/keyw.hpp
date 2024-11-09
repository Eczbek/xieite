#pragma once

#include <xieite/arrow.hpp>
#include <xieite/fn.hpp>
#include <xieite/fwd.hpp>

namespace std::chrono {}
namespace std::execution {}
namespace std::filesystem {}
namespace std::numbers {}
namespace std::placeholders {}
namespace std::ranges {}
namespace std::this_thread {}
namespace std::views {}
namespace std::experimental {}
namespace stdc = std::chrono;
namespace stde = std::execution;
namespace stdf = std::filesystem;
namespace stdn = std::numbers;
namespace stdp = std::placeholders;
namespace stdr = std::ranges;
namespace stdt = std::this_thread;
namespace stdv = std::views;
namespace stdx = std::experimental;

#define nand && XIEITE_DETAIL::ifx<XIEITE_FN(!XIEITE_FWD($0) || !XIEITE_FWD($1))>() &&
#define nor || XIEITE_DETAIL::ifx<XIEITE_FN(!XIEITE_FWD($0) && !XIEITE_FWD($1))>() ||
#define xnor ^ XIEITE_DETAIL::ifx<XIEITE_FN(XIEITE_FWD($0) == XIEITE_FWD($1))>() ^
#define imply || XIEITE_DETAIL::ifx<XIEITE_FN(!XIEITE_FWD($0) || XIEITE_FWD($1))>() ||
#define nimply && XIEITE_DETAIL::ifx<XIEITE_FN(XIEITE_FWD($0) && !XIEITE_FWD($1))>() &&
#define eq_not XIEITE_DETAIL::pfx<XIEITE_FN($0 = !$0)>() ->*
#define nand_eq = XIEITE_DETAIL::ifx<XIEITE_FN($0 = !$0 || !XIEITE_FWD($1))>() +=
#define nor_eq = XIEITE_DETAIL::ifx<XIEITE_FN($0 = !$0 && !XIEITE_FWD($1))>() +=
#define xnor_eq = XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 == XIEITE_FWD($1))>() +=
#define imply_eq || XIEITE_DETAIL::ifx<XIEITE_FN($0 = !$0 || XIEITE_FWD($1))>() ||
#define nimply_eq && XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 && !XIEITE_FWD($1))>() &&
#define bitnand & XIEITE_DETAIL::ifx<XIEITE_FN(~XIEITE_FWD($0) | ~XIEITE_FWD($1))>() &
#define bitnor | XIEITE_DETAIL::ifx<XIEITE_FN(~XIEITE_FWD($0) & ~XIEITE_FWD($1))>() |
#define bitxnor ^ XIEITE_DETAIL::ifx<XIEITE_FN(~(~XIEITE_FWD($0) ^ ~XIEITE_FWD($1)))>() ^
#define bitimply | XIEITE_DETAIL::ifx<XIEITE_FN(~XIEITE_FWD($0) | XIEITE_FWD($1))>() |
#define bitnimply & XIEITE_DETAIL::ifx<XIEITE_FN(XIEITE_FWD($0) & ~XIEITE_FWD($1))>() &
#define eq_compl XIEITE_DETAIL::pfx<XIEITE_FN($0 = ~$0)>() ->*
#define bitand_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 & XIEITE_FWD($1))>() +=
#define bitnand_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 bitnand XIEITE_FWD($1))>() +=
#define bitor_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 | XIEITE_FWD($1))>() +=
#define bitnor_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 bitnor XIEITE_FWD($1))>() +=
#define bitxor_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 ^ XIEITE_FWD($1))>() +=
#define bitxnor_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 bitxnor XIEITE_FWD($1))>() +=
#define bitimply_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = ~$0 | XIEITE_FWD($1))>() +=
#define bitnimply_eq += XIEITE_DETAIL::ifx<XIEITE_FN($0 = $0 & ~XIEITE_FWD($1))>() +=

#define ifn(...) if (__VA_ARGS__, XIEITE_DETAIL::negate())
#define elif else if
#define elifn(...) else ifn
#define if_try(...) \
	if (([&] -> bool { \
		try { \
			__VA_ARGS__; \
			return true; \
		} catch (...) { \
			return false; \
		} \
	})())
#define ifn_try(...) if_try (__VA_ARGS__, XIEITE_DETAIL::negate())
#define elif_try else if_try
#define elifn_try else ifn_try
#define if_requires(...) if constexpr (requires { __VA_ARGS__; })
#define ifn_requires(...) if_requires (__VA_ARGS__) {} elif (true)
#define elif_requires else if_requires
#define elifn_requires else ifn_requires
#define if_for(...) \
	for (XIEITE_DETAIL::loop_state XIEITE_DETAIL_LOOP_STATE; XIEITE_DETAIL_LOOP_STATE.flag && !XIEITE_DETAIL_LOOP_STATE.broke; --XIEITE_DETAIL_LOOP_STATE.flag) \
		if ((XIEITE_DETAIL_LOOP_STATE.flag == 2) && !XIEITE_DETAIL_LOOP_STATE.broke) \
			for (__VA_ARGS__ + *XIEITE_DETAIL_LOOP_STATE) \
				if ((XIEITE_DETAIL_LOOP_STATE.broke = false)); \
				else
#define elif_for else if_for
#define if_while(...) if_for (; __VA_ARGS__;)
#define elif_while else if_while

#define of :
#define extends :
#define inits :

#define lest break; case
#define yet break; default
#define perchance continue; case
#define otherwise continue; default

#define implicit explicit(false)
#define except noexcept(false)

namespace XIEITE_DETAIL {
	template<auto fn>
	struct ifx {
		template<typename Type>
		struct inter {
			Type&& left;

			[[nodiscard]] constexpr auto operator->*(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator*(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator&(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator^(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator|(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator&&(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] constexpr auto operator||(Type&& right) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->left), XIEITE_FWD(right)))

			[[nodiscard]] friend constexpr auto operator+=(Type&& right, inter self)
			XIEITE_ARROW(fn(XIEITE_FWD(self.left), XIEITE_FWD(right)))
		};

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator->*(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator*(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator&(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator^(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator|(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator&&(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		template<typename Type>
		[[nodiscard]] friend constexpr auto operator||(Type&& left, ifx)
		XIEITE_ARROW(ifx::inter<Type>(XIEITE_FWD(left)))

		[[nodiscard]] constexpr auto operator+=(auto&& left) const
		XIEITE_ARROW(ifx::inter<decltype(left)>(XIEITE_FWD(left)))
	};

	template<auto fn>
	struct pfx {
		[[nodiscard]] constexpr auto operator->*(auto&& right)
		XIEITE_ARROW(fn(XIEITE_FWD(right)))
	};

	struct negate {
		[[nodiscard]] friend constexpr auto operator,(auto&& value, negate)
		XIEITE_ARROW(static_cast<bool>(!XIEITE_FWD(value)))
	};

	struct loop_state {
		int flag = 2;
		bool broke = false;

		constexpr void operator+() noexcept {
			this->broke = true;
		}

		friend constexpr auto&& operator+(auto&& value, XIEITE_DETAIL::loop_state) noexcept {
			this->broke = true;
			return XIEITE_FWD(value);
		}
	};
}

// Loop macros originally stolen from m1lkweed (https://gist.github.com/m1lkweed/3be672402c43ac5697f1e29bcb79e004)
