#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_BOOL_TESTABLE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_BOOL_TESTABLE
#
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	concept is_noex_bool_testable = requires(T&& x) {
		{ static_cast<bool>(XIEITE_FWD(x)) } noexcept;
		{ static_cast<bool>(!XIEITE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(XIEITE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(!XIEITE_FWD(x)) } noexcept;
		// TODO: Check `operator&&()` and `operator||()` to best ability
	};
}

#endif
