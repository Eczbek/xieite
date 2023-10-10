#pragma once

#include "../macros/compiler.hpp"

#if XIEITE_COMPILER_GCC
#	include <string_view>
#	include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", ";");
	}
}

#elif XIEITE_COMPILER_LLVM
#	include <string_view>
#	include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(__PRETTY_FUNCTION__, "= ", "]");
	}
}

#elif XIEITE_COMPILER_MSVC
#	include <string_view>
#	include "../strings/after.hpp"
#	include "../strings/between.hpp"

namespace xieite::types {
	template<typename Type>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		return xieite::strings::between(xieite::strings::after(__FUNCSIG__, "__cdecl"), "<", ">(");
	}
}

#else
#	error "Compiler not supported"
#endif
