#ifndef XIEITE_HEADER_TYPES_NAME
#	define XIEITE_HEADER_TYPES_NAME

#	include <string_view>
#	include "../containers/make_array.hpp"
#	include "../macros/compiler.hpp"
#	include "../macros/function_signature.hpp"
#	include "../strings/between.hpp"

#	if XIEITE_COMPILER_TYPE_MSVC
#		include "../strings/after.hpp"
#	endif

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename _>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto get = [string = std::string_view(XIEITE_FUNCTION_SIGNATURE)] {
#	if XIEITE_COMPILER_TYPE_GCC
			return xieite::strings::between(string, "= ", ';');
#	elif XIEITE_COMPILER_TYPE_CLANG
			return xieite::strings::between(string, "= ", ']');
#	elif XIEITE_COMPILER_TYPE_WINDOWS
			return xieite::strings::between(xieite::strings::after(string, " __"), '<', ">(");
#	endif
		};
		static constexpr auto data = xieite::containers::makeArray<char, get().size()>(get());
		return std::string_view(data.begin(), data.end());
	}
}

namespace xieite::types {
	template<typename Type>
	inline constexpr std::string_view name = XIEITE_DETAIL_NAMESPACE::name<Type>();
}

#endif
