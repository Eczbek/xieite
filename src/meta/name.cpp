module;

#include <xieite/cplr.hpp>
#include <xieite/fn_sig.hpp>

export module xieite:name;

import std;
import :str_after;
import :str_betw;

namespace detail::name {
	[[nodiscard]] consteval std::string_view parse(std::string_view name) noexcept {
#if XIEITE_CPLR_TYPE_CLANG || XIEITE_CPLR_TYPE_ICC
		return xieite::str_betw(name, "= ", ']');
#elif XIEITE_CPLR_TYPE_GCC
		return xieite::str_betw(name, "= ", ';');
#elif XIEITE_CPLR_TYPE_MSVC
		return xieite::str_betw(xieite::str_after(name, " __"), '<', ">(");
#else
		return "???";
#endif
	}

	template<typename _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return detail::name::parse(XIEITE_FN_SIG);
	}

	template<auto _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return detail::name::parse(XIEITE_FN_SIG);
	}
}

export namespace xieite {
	template<typename T>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return detail::name::get<T>();
	}

	template<auto x>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return detail::name::get<x>();
	}
}
