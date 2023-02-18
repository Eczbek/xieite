#pragma once
#include <cxxabi.h> // abi::__cxa_demangle
#include <string> // std::string
#include <string_view> // std::string_view

// Thanks to eightfold for idea

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
