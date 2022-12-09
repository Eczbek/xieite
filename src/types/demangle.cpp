#include <cxxabi.h> // abi::__cxa_demangle
#include <string> // std::string
#include <string_view> // std::string_view
#include <xieite/types/demangle.hpp> // xieite::types::demangle

std::string xieite::types::demangle(const std::string_view mangled) noexcept {
	int status;
	const char* demangled = abi::__cxa_demangle(mangled.data(), 0, 0, &status);
	return std::string(status
		? mangled
		: demangled);
}
