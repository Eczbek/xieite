#ifndef DETAIL_XTE_HEADER_TRAIT_IS_BOOL_TESTABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_BOOL_TESTABLE_NOEX
#
#	include "../preproc/fwd.hpp"

namespace xte {
	template<typename T>
	concept is_bool_testable_noex = requires (T&& x, [:^^int(bool) noexcept:]& f) {
		{ static_cast<bool>(XTE_FWD(x)) } noexcept;
		{ static_cast<bool>(!XTE_FWD(x)) } noexcept;
		{ f(XTE_FWD(x)) } noexcept;
		{ f(!XTE_FWD(x)) } noexcept;
		// TODO: Check `operator&&()` and `operator||()` to best ability
	};
}

#endif
