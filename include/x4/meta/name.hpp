#pragma once

#include <string_view>
#include "../ctnr/strafter.hpp"
#include "../ctnr/strbetw.hpp"
#include "../pp/cplr.hpp"
#include "../pp/fnsig.hpp"

namespace DETAIL_X4::name {
	[[nodiscard]] consteval std::string_view parse(std::string_view name) noexcept {
#if X4CPLR_CLANG || X4CPLR_ICC
		return x4::strbetw(name, "= ", ']');
#elif X4CPLR_GCC
		return x4::strbetw(name, "= ", ';');
#elif X4CPLR_MSVC
		return x4::strbetw(x4::strafter(name, " __"), '<', ">(");
#else
		return "???";
#endif
	}

	template<typename _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_X4::name::parse(X4FNSIG);
	}

	template<auto _>
	[[nodiscard]] consteval std::string_view get() noexcept {
		return DETAIL_X4::name::parse(X4FNSIG);
	}
}

namespace x4 {
	template<typename T>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return DETAIL_X4::name::get<T>();
	}

	template<auto x>
	[[nodiscard]] consteval std::string_view name() noexcept {
		return DETAIL_X4::name::get<x>();
	}
}
