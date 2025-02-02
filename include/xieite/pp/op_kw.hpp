#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fn.hpp"
#include "../pp/fwd.hpp"

#define nand && XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(!XIEITE_FWD($0) || !XIEITE_FWD($1))>() &&
#define nor || XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(!XIEITE_FWD($0) && !XIEITE_FWD($1))>() ||
#define xnor ^ XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(XIEITE_FWD($0) == XIEITE_FWD($1))>() ^
#define imply || XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(!XIEITE_FWD($0) || XIEITE_FWD($1))>() ||
#define nimply && XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(XIEITE_FWD($0) && !XIEITE_FWD($1))>() &&
#define eq_not XIEITE_DETAIL::OP_KW::pfx<XIEITE_FN($0 = !$0)>() ->*
#define nand_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = !$0 || !XIEITE_FWD($1))>() +=
#define nor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = !$0 && !XIEITE_FWD($1))>() +=
#define xnor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 == XIEITE_FWD($1))>() +=
#define imply_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = !$0 || XIEITE_FWD($1))>() +=
#define nimply_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 && !XIEITE_FWD($1))>() +=
#define bitnand & XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(~XIEITE_FWD($0) | ~XIEITE_FWD($1))>() &
#define bitnor | XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(~XIEITE_FWD($0) & ~XIEITE_FWD($1))>() |
#define bitxnor ^ XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(~(~XIEITE_FWD($0) ^ ~XIEITE_FWD($1)))>() ^
#define bitimply | XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(~XIEITE_FWD($0) | XIEITE_FWD($1))>() |
#define bitnimply & XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN(XIEITE_FWD($0) & ~XIEITE_FWD($1))>() &
#define eq_compl XIEITE_DETAIL::OP_KW::pfx<XIEITE_FN($0 = ~$0)>() ->*
#define bitand_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 & XIEITE_FWD($1))>() +=
#define bitnand_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 bitnand XIEITE_FWD($1))>() +=
#define bitor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 | XIEITE_FWD($1))>() +=
#define bitnor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 bitnor XIEITE_FWD($1))>() +=
#define bitxor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 ^ XIEITE_FWD($1))>() +=
#define bitxnor_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 bitxnor XIEITE_FWD($1))>() +=
#define bitimply_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = ~$0 | XIEITE_FWD($1))>() +=
#define bitnimply_eq += XIEITE_DETAIL::OP_KW::ifx<XIEITE_FN($0 = $0 & ~XIEITE_FWD($1))>() +=

namespace XIEITE_DETAIL::OP_KW {
	template<auto fn, typename T>
	struct proxy {
		T&& l;

		[[nodiscard]] constexpr auto operator->*(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator*(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator&(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator^(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator|(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator&&(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] constexpr auto operator||(T&& r) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->l), XIEITE_FWD(r)))

		[[nodiscard]] friend constexpr auto operator+=(T&& r, XIEITE_DETAIL::OP_KW::proxy<fn, T>&& self)
			XIEITE_ARROW(fn(XIEITE_FWD(self.l), XIEITE_FWD(r)))
	};

	template<auto fn>
	struct ifx {
		template<typename T>
		[[nodiscard]] friend constexpr auto operator->*(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator*(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator^(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator|(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&&(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator||(T&& l, XIEITE_DETAIL::OP_KW::ifx<fn>)
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] constexpr auto operator+=(T&& l) const
			XIEITE_ARROW(XIEITE_DETAIL::OP_KW::proxy<fn, T>(XIEITE_FWD(l)))
	};

	template<auto fn>
	struct pfx {
		[[nodiscard]] constexpr auto operator->*(auto&& r)
			XIEITE_ARROW(fn(XIEITE_FWD(r)))
	};
}
