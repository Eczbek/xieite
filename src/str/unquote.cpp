export module xieite:unquote;

import std;
import :str_replace;

export namespace xieite {
	[[nodiscard]] constexpr std::string unquote(std::string_view str, char delim = '"', char esc = '\\') noexcept {
		str.remove_prefix(str[0] == delim);
		str.remove_suffix(str[str.size() - 1] == delim);
		const std::string esc_delim = std::string(1, esc) + delim;
		if (delim == esc) {
			return xieite::str_replace(str, esc_delim, delim);
		} else {
			return xieite::str_replace(xieite::str_replace(str, std::string(2, esc), esc), esc_delim, delim);
		}
	}
}
