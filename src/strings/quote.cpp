export module xieite:strings.quote;

import std;
import :strings.replace;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string quote(const std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		std::string result = std::string(1, delimiter);
		const std::string escapeDelimiter = std::string(1, escape) + delimiter;
		if (delimiter == escape) {
			result += xieite::strings::replace(value, delimiter, escapeDelimiter);
		} else {
			const std::string escapeEscape = std::string(2, escape);
			const std::string temporary = xieite::strings::replace(value, escape, escapeEscape);
			result += xieite::strings::replace(temporary, delimiter, escapeDelimiter);
		}
		return result + delimiter;
	}
}
