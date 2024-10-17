module;

#include <xieite/compiler.hpp>
#include <xieite/function_signature.hpp>

export module xieite:types.name;

import std;
import :containers.makeArray;
import :strings.after;
import :strings.between;

[[nodiscard]] consteval std::string_view getTypeName(const std::string_view signature) noexcept {
#if XIEITE_COMPILER_TYPE_GCC
	return xieite::strings::between(signature, "= ", ';');
#elif XIEITE_COMPILER_TYPE_CLANG
	return xieite::strings::between(signature, "= ", ']');
#elif XIEITE_COMPILER_TYPE_WINDOWS
	return xieite::strings::between(xieite::strings::after(signature, " __"), '<', ">(");
#endif
}

export namespace xieite::types {
	template<typename Type>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, getTypeName(XIEITE_FUNCTION_SIGNATURE).size()>(getTypeName(XIEITE_FUNCTION_SIGNATURE));
		return std::string_view(data.begin(), data.end());
	}

	template<auto value>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, getTypeName(XIEITE_FUNCTION_SIGNATURE).size()>(getTypeName(XIEITE_FUNCTION_SIGNATURE));
		return std::string_view(data.begin(), data.end());
	}
}
