#pragma once

#include <xieite/macros/SYSTEM_TYPE.hpp>

#if defined(XIEITE_SYSTEM_TYPE_LINUX)
#	include <cxxabi.h>
#	include <string>

namespace xieite::types {
	[[nodiscard]]
	inline std::string demangle(std::string mangled) noexcept {
		int status;
		char* buffer = abi::__cxa_demangle(mangled.data(), 0, 0, &status);
		if (!status) {
			mangled = std::string(buffer);
			free(buffer);
		}
		return mangled;
	}
}

#else
#	error "System not supported"
#endif

// Thanks to eightfold for idea
