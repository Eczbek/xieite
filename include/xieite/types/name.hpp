#ifndef XIEITE_HEADER__TYPES__NAME
#	define XIEITE_HEADER__TYPES__NAME

#	include "../macros/COMPILER_TYPE.hpp"

#	if XIEITE__COMPILER_TYPE__GCC
#		include <string_view>
#		include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", ";");
	}
}

#	elif XIEITE__COMPILER_TYPE__LLVM
#		include <string_view>
#		include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", "]");
	}
}

#	elif XIEITE__COMPILER_TYPE__MSVC
#		include <string_view>
#		include "../strings/after.hpp"
#		include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(xieite::strings::after(__FUNCSIG__, "__cdecl"), "<", ">(");
	}
}

#	else
#		error "Compiler not supported"
#	endif

#endif
