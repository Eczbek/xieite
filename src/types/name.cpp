module;

#include <xieite/compiler.hpp>
#include <xieite/function_signature.hpp>

export module xieite:types.name;

import std;
import :containers.makeArray;
import :strings.after;
import :strings.between;

template<typename _>
[[nodiscard]] consteval std::string_view getName() noexcept {
	static constexpr auto get = [string = std::string_view(XIEITE_FUNCTION_SIGNATURE)] -> std::string_view {
#if XIEITE_COMPILER_TYPE_GCC
		return xieite::strings::between(string, "= ", ';');
#elif XIEITE_COMPILER_TYPE_CLANG
		return xieite::strings::between(string, "= ", ']');
#elif XIEITE_COMPILER_TYPE_WINDOWS
		return xieite::strings::between(xieite::strings::after(string, " __"), '<', ">(");
#endif
	};
	static constexpr auto data = xieite::containers::makeArray<char, get().size()>(get());
	return std::string_view(data.begin(), data.end());
}

export namespace xieite::types {
	template<typename Type>
	inline constexpr std::string_view name = getName<Type>();
}

// TODO: Remove `inline` once wreien fixes related bug next week
