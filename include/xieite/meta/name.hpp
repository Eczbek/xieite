#pragma once

#include <string_view>
#include "../ctnr/str_after.hpp"
#include "../ctnr/str_betw.hpp"
#include "../pp/compiler.hpp"
#include "../pp/fn_sig.hpp"

namespace DETAIL_XIEITE::name {
	[[nodiscard]] consteval std::string_view parse(std::string_view name) noexcept {
#if XIEITE_COMPILER_TYPE_CLANG || XIEITE_COMPILER_TYPE_ICC
		return xieite::str_betw(name, "= ", ']');
#elif XIEITE_COMPILER_TYPE_GCC
		return xieite::str_betw(name, "= ", ';');
#elif XIEITE_COMPILER_TYPE_MSVC
		return xieite::str_betw(xieite::str_after(name, " __"), '<', ">(");
#else
		return "???";
#endif
	}

	template<typename _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_XIEITE::name::parse(XIEITE_FN_SIG);
	}

	template<auto _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_XIEITE::name::parse(XIEITE_FN_SIG);
	}
}

namespace xieite {
	template<typename T>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return DETAIL_XIEITE::name::get<T>();
	}

	template<auto x>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return DETAIL_XIEITE::name::get<x>();
	}
}
