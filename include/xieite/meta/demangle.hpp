#ifndef DETAIL_XIEITE_HEADER_META_DEMANGLE
#	define DETAIL_XIEITE_HEADER_META_DEMANGLE
#
#	include <cstdlib>
#	include <string>
#
#	if __has_include(<cxxabi.h>)
#		include <cxxabi.h>
#	endif

namespace xieite {
	[[nodiscard]] inline std::string demangle(const std::string& mangled) noexcept {
#	if __has_include(<cxxabi.h>)
		if (char* const buf = abi::__cxa_demangle(mangled.c_str(), nullptr, nullptr, nullptr)) {
			const std::string demangled = std::string(buf);
			std::free(buf);
			return demangled;
		}
#	endif
		return mangled;
	}
}

#endif

// https://itanium-cxx-abi.github.io/cxx-abi/abi.html#demangler
