#ifndef DETAIL_XIEITE_HEADER_PP_KEYWORDS
#	define DETAIL_XIEITE_HEADER_PP_KEYWORDS
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define nand && DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) || !XIEITE_FWD(y); })>() &&
#	define nor || DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) && !XIEITE_FWD(y); })>() ||
#	define xnor ^ DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) == XIEITE_FWD(y); })>() ^
#	define imply || DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) || XIEITE_FWD(y); })>() ||
#	define nimply && DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) && !XIEITE_FWD(y); })>() &&
#	define eq_not DETAIL_XIEITE::KEYWORDS::pfx<([](auto&& x) static { return x = !x; })>() ->*
#	define nand_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x || !XIEITE_FWD(y); })>() +=
#	define nor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x && !XIEITE_FWD(y); })>() +=
#	define xnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x == XIEITE_FWD(y); })>() +=
#	define imply_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x || XIEITE_FWD(y); })>() +=
#	define nimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x && !XIEITE_FWD(y); })>() +=
#	define bitnand & DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) | ~XIEITE_FWD(y); })>() &
#	define bitnor | DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) & ~XIEITE_FWD(y); })>() |
#	define bitxnor ^ DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~(~XIEITE_FWD(x) ^ ~XIEITE_FWD(y)); })>() ^
#	define bitimply | DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) | XIEITE_FWD(y); })>() |
#	define bitnimply & DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) & ~XIEITE_FWD(y); })>() &
#	define eq_compl DETAIL_XIEITE::KEYWORDS::pfx<([](auto&& x) static { return x = ~x; })>() ->*
#	define bitand_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x & XIEITE_FWD(y); })>() +=
#	define bitnand_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitnand XIEITE_FWD(y); })>() +=
#	define bitor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x | XIEITE_FWD(y); })>() +=
#	define bitnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitnor XIEITE_FWD(y); })>() +=
#	define bitxor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x ^ XIEITE_FWD(y); })>() +=
#	define bitxnor_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitxnor XIEITE_FWD(y); })>() +=
#	define bitimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = ~x | XIEITE_FWD(y); })>() +=
#	define bitnimply_eq += DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x & ~XIEITE_FWD(y); })>() +=

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

#endif
