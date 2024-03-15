#ifndef XIEITE_HEADER_STRINGS_REPLACE
#	define XIEITE_HEADER_STRINGS_REPLACE

#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view replace, const std::string_view with, const std::size_t start = 0) noexcept {
		std::string result = std::string(value);
		std::size_t i = start;
		while (true) {
			i = result.find(replace, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, replace.size(), with);
			i += with.size();
		}
		return result;
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char replace, const std::string_view with, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, std::string_view(&replace, 1), with, start);
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view replace, const char with, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, replace, std::string_view(&with, 1), start);
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char replace, const char with, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, std::string_view(&replace, 1), std::string_view(&with, 1), start);
	}
}

#endif
