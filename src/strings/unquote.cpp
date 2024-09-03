export module xieite:strings.unquote;

import std;
import :strings.replace;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string unquote(std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		value.remove_prefix(value[0] == delimiter);
		value.remove_suffix(value[value.size() - 1] == delimiter);
		const std::string escapeDelimiter = std::string(1, escape) + delimiter;
		if (delimiter == escape) {
			return xieite::strings::replace(value, escapeDelimiter, delimiter);
		} else {
			const std::string escapeEscape = std::string(2, escape);
			const std::string temporary = xieite::strings::replace(value, escapeEscape, escape);
			return xieite::strings::replace(temporary, escapeDelimiter, delimiter);
		}
	}
}
