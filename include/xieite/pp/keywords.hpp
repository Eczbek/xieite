#ifndef DETAIL_XIEITE_HEADER_PP_KEYWORDS
#	define DETAIL_XIEITE_HEADER_PP_KEYWORDS
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define nand && DETAIL_XIEITE::KEYWORDS::nand_impl &&
#	define nor || DETAIL_XIEITE::KEYWORDS::nor_impl ||
#	define xnor ^ DETAIL_XIEITE::KEYWORDS::xnor_impl ^
#	define imply || DETAIL_XIEITE::KEYWORDS::imply_impl ||
#	define nimply && DETAIL_XIEITE::KEYWORDS::nimply_impl &&
#	define eq_not DETAIL_XIEITE::KEYWORDS::eq_not_impl ->*
#	define nand_eq += DETAIL_XIEITE::KEYWORDS::nand_eq_impl +=
#	define nor_eq += DETAIL_XIEITE::KEYWORDS::nor_eq_impl +=
#	define xnor_eq += DETAIL_XIEITE::KEYWORDS::xnor_eq_impl +=
#	define imply_eq += DETAIL_XIEITE::KEYWORDS::imply_eq_impl +=
#	define nimply_eq += DETAIL_XIEITE::KEYWORDS::nimply_eq_impl +=
#	define bitnand & DETAIL_XIEITE::KEYWORDS::bitnand_impl &
#	define bitnor | DETAIL_XIEITE::KEYWORDS::bitnor_impl |
#	define bitxnor ^ DETAIL_XIEITE::KEYWORDS::bitxnor_impl ^
#	define bitimply | DETAIL_XIEITE::KEYWORDS::bitimply_impl |
#	define bitnimply & DETAIL_XIEITE::KEYWORDS::bitnimply_impl &
#	define eq_compl DETAIL_XIEITE::KEYWORDS::eq_compl_impl ->*
#	define bitand_eq += DETAIL_XIEITE::KEYWORDS::bitand_eq_impl +=
#	define bitnand_eq += DETAIL_XIEITE::KEYWORDS::bitnand_eq_impl +=
#	define bitor_eq += DETAIL_XIEITE::KEYWORDS::bitor_eq_impl +=
#	define bitnor_eq += DETAIL_XIEITE::KEYWORDS::bitnor_eq_impl +=
#	define bitxnor_eq += DETAIL_XIEITE::KEYWORDS::bitxnor_eq_impl +=
#	define bitimply_eq += DETAIL_XIEITE::KEYWORDS::bitimply_eq_impl +=
#	define bitnimply_eq += DETAIL_XIEITE::KEYWORDS::bitnimply_eq_impl +=

namespace DETAIL_XIEITE::KEYWORDS {
	template<auto fn, typename Arg>
	struct proxy {
		Arg&& lhs;

		[[nodiscard]] constexpr auto operator->*(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator*(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator&(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator^(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator|(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator&&(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] constexpr auto operator||(Arg&& rhs) const
			XIEITE_ARROW(fn(XIEITE_FWD(this->lhs), XIEITE_FWD(rhs)))

		[[nodiscard]] friend constexpr auto operator+=(Arg&& rhs, DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>&& self)
			XIEITE_ARROW(fn(XIEITE_FWD(self.lhs), XIEITE_FWD(rhs)))
	};

	template<auto fn>
	struct ifx {
		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator->*(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator*(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator&(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator^(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator|(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator&&(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] friend constexpr auto operator||(Arg&& lhs, DETAIL_XIEITE::KEYWORDS::ifx<fn>)
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))

		template<typename Arg>
		[[nodiscard]] constexpr auto operator+=(Arg&& lhs) const
			XIEITE_ARROW(DETAIL_XIEITE::KEYWORDS::proxy<fn, Arg>(XIEITE_FWD(lhs)))
	};

	template<auto fn>
	struct pfx {
		[[nodiscard]] constexpr auto operator->*(auto&& rhs)
			XIEITE_ARROW(fn(XIEITE_FWD(rhs)))
	};

	inline constexpr auto nand_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) || !XIEITE_FWD(y); })>();
	inline constexpr auto nor_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) && !XIEITE_FWD(y); })>();
	inline constexpr auto xnor_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) == XIEITE_FWD(y); })>();
	inline constexpr auto imply_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return !XIEITE_FWD(x) || XIEITE_FWD(y); })>();
	inline constexpr auto nimply_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) && !XIEITE_FWD(y); })>();
	inline constexpr auto eq_not_impl = DETAIL_XIEITE::KEYWORDS::pfx<([](auto&& x) static { return x = !x; })>();
	inline constexpr auto nand_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x || !XIEITE_FWD(y); })>();
	inline constexpr auto nor_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x && !XIEITE_FWD(y); })>();
	inline constexpr auto xnor_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x == XIEITE_FWD(y); })>();
	inline constexpr auto imply_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = !x || XIEITE_FWD(y); })>();
	inline constexpr auto nimply_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x && !XIEITE_FWD(y); })>();
	inline constexpr auto bitnand_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) | ~XIEITE_FWD(y); })>();
	inline constexpr auto bitnor_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) & ~XIEITE_FWD(y); })>();
	inline constexpr auto bitxnor_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~(~XIEITE_FWD(x) ^ ~XIEITE_FWD(y)); })>();
	inline constexpr auto bitimply_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return ~XIEITE_FWD(x) | XIEITE_FWD(y); })>();
	inline constexpr auto bitnimply_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return XIEITE_FWD(x) & ~XIEITE_FWD(y); })>();
	inline constexpr auto eq_compl_impl = DETAIL_XIEITE::KEYWORDS::pfx<([](auto&& x) static { return x = ~x; })>();
	inline constexpr auto bitand_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x & XIEITE_FWD(y); })>();
	inline constexpr auto bitnand_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitnand XIEITE_FWD(y); })>();
	inline constexpr auto bitor_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x | XIEITE_FWD(y); })>();
	inline constexpr auto bitnor_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitnor XIEITE_FWD(y); })>();
	inline constexpr auto bitxnor_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x bitxnor XIEITE_FWD(y); })>();
	inline constexpr auto bitimply_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = ~x | XIEITE_FWD(y); })>();
	inline constexpr auto bitnimply_eq_impl = DETAIL_XIEITE::KEYWORDS::ifx<([](auto&& x, auto&& y) static { return x = x & ~XIEITE_FWD(y); })>();
}

#endif
