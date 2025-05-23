#ifndef DETAIL_XIEITE_HEADER_META_DEMANGLE
#	define DETAIL_XIEITE_HEADER_META_DEMANGLE
#
#	include <cstdlib>
#	include <string>
#	include <string_view>
#
#	if __has_include(<cxxabi.h>)
#		include <cxxabi.h>
#	endif

namespace xieite {
	[[nodiscard]] inline std::string demangle(std::string_view name) noexcept {
#	if __has_include(<cxxabi.h>)
		auto result = std::string(name);
		if (char* const buf = abi::__cxa_demangle(result.c_str(), nullptr, nullptr, nullptr)) {
			result = std::string(buf);
			std::free(buf);
		}
#	endif
		return result;
	}
}

#endif

// https://itanium-cxx-abi.github.io/cxx-abi/abi.html#demangler
