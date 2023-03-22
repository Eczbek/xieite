#pragma once

#include <cxxabi.h>
#include <string>
#include <string_view>

namespace xieite::types {
	[[nodiscard]]
	inline std::string demangle(const std::string_view mangled) noexcept {
		int status;
		char* buffer = abi::__cxa_demangle(mangled.data(), 0, 0, &status);
		std::string demangled(mangled);
		if (!status) {
			demangled = std::string(buffer);
			free(buffer);
		}
		return demangled;
	}
}

// Thanks to eightfold for idea
