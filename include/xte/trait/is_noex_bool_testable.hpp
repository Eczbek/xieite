#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_BOOL_TESTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_BOOL_TESTABLE
#
#	include "../preproc/fwd.hpp"

namespace xte {
	template<typename T>
	concept is_noex_bool_testable = requires (T&& x) {
		{ static_cast<bool>(XTE_FWD(x)) } noexcept;
		{ static_cast<bool>(!XTE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(XTE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(!XTE_FWD(x)) } noexcept;
		// TODO: Check `operator&&()` and `operator||()` to best ability
	};
}

#endif
