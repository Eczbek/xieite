#ifndef XIEITE_HEADER_STRINGS_BETWEEN
#	define XIEITE_HEADER_STRINGS_BETWEEN

#	include <string_view>
#	include "../strings/after.hpp"
#	include "../strings/before.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const std::string_view start, const std::string_view end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const std::string_view start, const char end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const char start, const std::string_view end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const char start, const char end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}
}

#endif
