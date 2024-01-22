#ifndef XIEITE_HEADER_TYPES_NAME
#	define XIEITE_HEADER_TYPES_NAME

#	include <string_view>
#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC
#		include "../strings/between.hpp"

namespace XIEITE_INTERNAL_TYPES_NAME {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", ';');
	}
}

#	elif XIEITE_COMPILER_TYPE_LLVM
#		include "../strings/between.hpp"

namespace XIEITE_INTERNAL_TYPES_NAME {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", ']');
	}
}

#	elif XIEITE_COMPILER_TYPE_MSVC
#		include "../strings/after.hpp"
#		include "../strings/between.hpp"

namespace XIEITE_INTERNAL_TYPES_NAME {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(xieite::strings::after(__FUNCSIG__, "__cdecl"), '<', ">(");
	}
}

#	else
#		error "Compiler not supported"
#	endif

namespace xieite::types {
	template<typename Type>
	inline constexpr std::string_view name = XIEITE_INTERNAL_TYPES_NAME::name<Type>();
}

#endif
