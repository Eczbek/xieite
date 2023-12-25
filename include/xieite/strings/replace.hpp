#ifndef XIEITE_HEADER_STRINGS_REPLACE
#	define XIEITE_HEADER_STRINGS_REPLACE

#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view target, const std::string_view replacement, const std::size_t start = 0) noexcept {
		std::string result = std::string(value);
		std::size_t i = start;
		while (true) {
			i = result.find(target, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, target.size(), replacement);
			i += target.size() + 1;
		}
		return result;
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char target, const std::string_view replacement, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, std::string(1, target), replacement, start);
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view target, const char replacement, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, target, std::string(1, replacement), start);
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char target, const char replacement, const std::size_t start = 0) noexcept {
		return xieite::strings::replace(value, std::string(1, target), std::string(1, replacement), start);
	}
}

#endif
