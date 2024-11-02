module;

#include <cxxabi.h>

export module xieite:demangle;

import std;

export namespace xieite {
	[[nodiscard]] std::string demangle(std::string_view mangled) noexcept {
		char* const buf = abi::__cxa_demangle(std::string(mangled).c_str(), nullptr, nullptr, nullptr);
		if (buf) {
			const std::string demangled = std::string(buf);
			std::free(buf);
			return demangled;
		}
		// No need to `free()` if demangling fails
		return mangled;
	}
}
