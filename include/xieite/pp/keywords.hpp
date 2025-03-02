#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fn.hpp"
#include "../pp/fwd.hpp"

#define nand && DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(!XIEITE_FWD($0) || !XIEITE_FWD($1))>() &&
#define nor || DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(!XIEITE_FWD($0) && !XIEITE_FWD($1))>() ||
#define xnor ^ DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(XIEITE_FWD($0) == XIEITE_FWD($1))>() ^
#define imply || DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(!XIEITE_FWD($0) || XIEITE_FWD($1))>() ||
#define nimply && DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(XIEITE_FWD($0) && !XIEITE_FWD($1))>() &&
#define eq_not DETAIL_XIEITE::KEYWORDS::pfx<XIEITE_FN($0 = !$0)>() ->*
#define nand_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = !$0 || !XIEITE_FWD($1))>() +=
#define nor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = !$0 && !XIEITE_FWD($1))>() +=
#define xnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 == XIEITE_FWD($1))>() +=
#define imply_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = !$0 || XIEITE_FWD($1))>() +=
#define nimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 && !XIEITE_FWD($1))>() +=
#define bitnand & DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(~XIEITE_FWD($0) | ~XIEITE_FWD($1))>() &
#define bitnor | DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(~XIEITE_FWD($0) & ~XIEITE_FWD($1))>() |
#define bitxnor ^ DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(~(~XIEITE_FWD($0) ^ ~XIEITE_FWD($1)))>() ^
#define bitimply | DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(~XIEITE_FWD($0) | XIEITE_FWD($1))>() |
#define bitnimply & DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN(XIEITE_FWD($0) & ~XIEITE_FWD($1))>() &
#define eq_compl DETAIL_XIEITE::KEYWORDS::pfx<XIEITE_FN($0 = ~$0)>() ->*
#define bitand_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 & XIEITE_FWD($1))>() +=
#define bitnand_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 bitnand XIEITE_FWD($1))>() +=
#define bitor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 | XIEITE_FWD($1))>() +=
#define bitnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 bitnor XIEITE_FWD($1))>() +=
#define bitxor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 ^ XIEITE_FWD($1))>() +=
#define bitxnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 bitxnor XIEITE_FWD($1))>() +=
#define bitimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = ~$0 | XIEITE_FWD($1))>() +=
#define bitnimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<XIEITE_FN($0 = $0 & ~XIEITE_FWD($1))>() +=

namespace DETAIL_XIEITE::KEYWORDS {
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

		[[nodiscard]] friend constexpr auto operator+=(T&& r, DETAIL_XIEITE::KEYWORDS::proxy<fn, T>&& self)
			XIEITE_ARROW(fn(XIEITE_FWD(self.l), XIEITE_FWD(r)))
	};

	template<auto fn>
	struct ifx {
		template<typename T>
		[[nodiscard]] friend constexpr auto operator->*(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator*(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator^(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator|(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&&(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator||(T&& l, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))

		template<typename T>
		[[nodiscard]] constexpr auto operator+=(T&& l) const
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, T>(XIEITE_FWD(l)))
	};

	template<auto fn>
	struct pfx {
		[[nodiscard]] constexpr auto operator->*(auto&& r)
			XIEITE_ARROW(fn(XIEITE_FWD(r)))
	};
}
