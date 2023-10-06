#ifndef XIEITE_HEADER__STRINGS__BETWEEN
#	define XIEITE_HEADER__STRINGS__BETWEEN

#	include <string>
#	include <string_view>
#	include "../strings/after.hpp"
#	include "../strings/before.hpp"

namespace xieite::strings {
	constexpr std::string_view between(const std::string_view string, const std::string_view start, const std::string_view end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	constexpr std::string_view between(const std::string_view string, const std::string_view start, const char end) noexcept {
		return xieite::strings::between(string, start, std::string(1, end));
	}

	constexpr std::string_view between(const std::string_view string, const char start, const std::string_view end) noexcept {
		return xieite::strings::between(string, std::string(1, start), end);
	}

	constexpr std::string_view between(const std::string_view string, const char start, const char end) noexcept {
		return xieite::strings::between(string, std::string(1, start), std::string(1, end));
	}
}

#endif
