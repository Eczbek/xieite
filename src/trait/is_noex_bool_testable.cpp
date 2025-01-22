module;

#include <xieite/fwd.hpp>

export module xieite:is_noex_bool_testable;

export namespace xieite {
	template<typename T>
	concept is_noex_bool_testable = requires(T&& x) {
		{ static_cast<bool>(XIEITE_FWD(x)) } noexcept;
		{ static_cast<bool>(!XIEITE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(XIEITE_FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(!XIEITE_FWD(x)) } noexcept;
	};
}

// TODO: Update when `xieite::is_bool_testable<>` is fixed
