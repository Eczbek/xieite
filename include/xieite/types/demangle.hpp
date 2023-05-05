#pragma once

#include <cxxabi.h>
#include <string>

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

// Thanks to eightfold for idea
