#ifndef XIEITE_HEADER_TYPES_DEMANGLE
#	define XIEITE_HEADER_TYPES_DEMANGLE

#	include "../macros/compiler.hpp"

#	if !XIEITE_COMPILER_TYPE_GCC
#		error "Compiler not supported"
#	endif

#	include <cstdlib>
#	include <cxxabi.h>
#	include <string>

namespace xieite::types {
	[[nodiscard]] inline std::string demangle(const std::string& mangled) noexcept {
		int status;
		char* const buffer = abi::__cxa_demangle(mangled.data(), nullptr, nullptr, &status);
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
