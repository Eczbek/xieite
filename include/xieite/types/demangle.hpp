#ifndef XIEITE_HEADER__TYPES__DEMANGLE
#	define XIEITE_HEADER__TYPES__DEMANGLE

#	include "../macros/compiler_type.hpp"

#	if !XIEITE__COMPILER_TYPE__GCC || !HAVE_CXA_DEMANGLE
#		error "Compiler not supported"
#	endif

#	include <cstdlib>
#	include <cxxabi.h>
#	include <string>

namespace xieite::types {
	[[nodiscard]] inline std::string demangle(const std::string& mangled) noexcept {
		char* const buffer = abi::__cxa_demangle(mangled.data(), nullptr, nullptr, nullptr);
		if (buffer) {
			const std::string demangled = std::string(buffer);
			std::free(buffer);
			return demangled;
		}
		// Buffer does not need to be freed if demangling fails
		return mangled;
	}
}

#endif
