#ifndef XIEITE_HEADER__STRINGS__BEFORE
#	define XIEITE_HEADER__STRINGS__BEFORE

#	include <string>
#	include <string_view>

namespace xieite::strings {
	constexpr std::string_view before(const std::string_view string, const std::string_view end) noexcept {
		return string.substr(0, string.find(end));
	}

	constexpr std::string_view before(const std::string_view string, const char end) noexcept {
		return xieite::strings::before(string, std::string(1, end));
}

#endif
