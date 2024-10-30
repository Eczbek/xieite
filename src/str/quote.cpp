export module xieite:quote;

import std;
import :str_replace;

export namespace xieite {
	[[nodiscard]] constexpr std::string quote(std::string_view str, char delim = '"', char esc = '\\') noexcept {
		std::string result = std::string(1, delim);
		const std::string esc_delim = std::string(1, esc) + delim;
		if (delim == esc) {
			result += xieite::str_replace(str, delim, esc_delim);
		} else {
			result += xieite::str_replace(xieite::str_replace(str, esc, std::string(2, esc)), delim, esc_delim);
		}
		return result + delim;
	}
}
