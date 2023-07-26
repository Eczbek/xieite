#ifndef XIEITE_HEADER_STRINGS_SOMETHING
#	define XIEITE_HEADER_STRINGS_SOMETHING

#	include <cmath>
#	include <string>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string something(const std::string& string) noexcept {
		return string.substr(std::log10(string.size() - std::log10(string.size())) + 1);
	}
}

// At some point I realized I can't explain this functionality or even describe a practical application

#endif
