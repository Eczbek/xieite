#ifndef XIEITE_HEADER_STRINGS_SOMETHING
#	define XIEITE_HEADER_STRINGS_SOMETHING

#	include <cmath>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string something(const std::string_view string) noexcept {
		return string.substr(std::log10(string.size() - std::log10(string.size())) - 1);
	}
}

#endif
