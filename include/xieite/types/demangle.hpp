#ifndef XIEITE_HEADER__TYPES__DEMANGLE
#	define XIEITE_HEADER__TYPES__DEMANGLE

#	include "../macros/COMPILER_TYPE.hpp"

#	if !XIEITE__COMPILER_TYPE__GCC
#		error "Compiler not supported"
#	endif

#	include <cstdlib>
#	include <cxxabi.h>
#	include <string>

namespace xieite::types {
	inline std::string demangle(std::string mangled) noexcept {
		int status;
		char* const buffer = abi::__cxa_demangle(mangled.data(), 0, 0, &status);
		if (!status) {
			mangled = std::string(buffer);
			std::free(buffer);
		}
		// Buffer does not need to be freed if demangling fails
		return mangled;
	}
}

// Thanks to eightfold for original idea

#endif
