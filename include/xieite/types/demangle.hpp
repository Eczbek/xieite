#ifndef XIEITE_HEADER_TYPES_DEMANGLE
#	define XIEITE_HEADER_TYPES_DEMANGLE

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstdlib>
#		include <cxxabi.h>
#		include <string>

namespace xieite::types {
	[[nodiscard]]
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

#	else
#		error "System not supported"
#	endif

// Thanks to eightfold for original idea

#endif
