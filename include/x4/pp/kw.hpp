#pragma once

#include "../pp/ar.hpp"
#include "../pp/fn.hpp"
#include "../pp/fwd.hpp"

#define nand && DETAIL_X4::KW::ifx<X4FN(!X4FWD($0) || !X4FWD($1))>() &&
#define nor || DETAIL_X4::KW::ifx<X4FN(!X4FWD($0) && !X4FWD($1))>() ||
#define xnor ^ DETAIL_X4::KW::ifx<X4FN(X4FWD($0) == X4FWD($1))>() ^
#define imply || DETAIL_X4::KW::ifx<X4FN(!X4FWD($0) || X4FWD($1))>() ||
#define nimply && DETAIL_X4::KW::ifx<X4FN(X4FWD($0) && !X4FWD($1))>() &&
#define eq_not DETAIL_X4::KW::pfx<X4FN($0 = !$0)>() ->*
#define nand_eq += DETAIL_X4::KW::ifx<X4FN($0 = !$0 || !X4FWD($1))>() +=
#define nor_eq += DETAIL_X4::KW::ifx<X4FN($0 = !$0 && !X4FWD($1))>() +=
#define xnor_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 == X4FWD($1))>() +=
#define imply_eq += DETAIL_X4::KW::ifx<X4FN($0 = !$0 || X4FWD($1))>() +=
#define nimply_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 && !X4FWD($1))>() +=
#define bitnand & DETAIL_X4::KW::ifx<X4FN(~X4FWD($0) | ~X4FWD($1))>() &
#define bitnor | DETAIL_X4::KW::ifx<X4FN(~X4FWD($0) & ~X4FWD($1))>() |
#define bitxnor ^ DETAIL_X4::KW::ifx<X4FN(~(~X4FWD($0) ^ ~X4FWD($1)))>() ^
#define bitimply | DETAIL_X4::KW::ifx<X4FN(~X4FWD($0) | X4FWD($1))>() |
#define bitnimply & DETAIL_X4::KW::ifx<X4FN(X4FWD($0) & ~X4FWD($1))>() &
#define eq_compl DETAIL_X4::KW::pfx<X4FN($0 = ~$0)>() ->*
#define bitand_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 & X4FWD($1))>() +=
#define bitnand_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 bitnand X4FWD($1))>() +=
#define bitor_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 | X4FWD($1))>() +=
#define bitnor_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 bitnor X4FWD($1))>() +=
#define bitxor_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 ^ X4FWD($1))>() +=
#define bitxnor_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 bitxnor X4FWD($1))>() +=
#define bitimply_eq += DETAIL_X4::KW::ifx<X4FN($0 = ~$0 | X4FWD($1))>() +=
#define bitnimply_eq += DETAIL_X4::KW::ifx<X4FN($0 = $0 & ~X4FWD($1))>() +=

namespace DETAIL_X4::KW {
	template<auto fn, typename T>
	struct proxy {
		T&& l;

		[[nodiscard]] constexpr auto operator->*(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator*(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator&(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator^(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator|(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator&&(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] constexpr auto operator||(T&& r) const
			X4AR(fn(X4FWD(this->l), X4FWD(r)))

		[[nodiscard]] friend constexpr auto operator+=(T&& r, DETAIL_X4::KW::proxy<fn, T>&& self)
			X4AR(fn(X4FWD(self.l), X4FWD(r)))
	};

	template<auto fn>
	struct ifx {
		template<typename T>
		[[nodiscard]] friend constexpr auto operator->*(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator*(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator^(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator|(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator&&(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] friend constexpr auto operator||(T&& l, DETAIL_X4::KW::ifx<fn>)
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))

		template<typename T>
		[[nodiscard]] constexpr auto operator+=(T&& l) const
			X4AR(DETAIL_X4::KW::proxy<fn, T>(X4FWD(l)))
	};

	template<auto fn>
	struct pfx {
		[[nodiscard]] constexpr auto operator->*(auto&& r)
			X4AR(fn(X4FWD(r)))
	};
}
