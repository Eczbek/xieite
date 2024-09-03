export module xieite:strings.replace;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view original, const std::string_view replacement) noexcept {
		std::string result = std::string(value);
		std::size_t i = 0;
		while (true) {
			i = result.find(original, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, original.size(), replacement);
			++i;
		}
		return result;
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char original, const std::string_view replacement) noexcept {
		return xieite::strings::replace(value, std::string_view(&original, 1), replacement);
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const std::string_view original, const char replacement) noexcept {
		return xieite::strings::replace(value, original, std::string_view(&replacement, 1));
	}

	[[nodiscard]] constexpr std::string replace(const std::string_view value, const char original, const char replacement) noexcept {
		return xieite::strings::replace(value, std::string_view(&original, 1), std::string_view(&replacement, 1));
	}
}
