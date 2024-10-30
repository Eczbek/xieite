export module xieite:str_split;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::vector<std::string_view> str_split(std::string_vie, xieite::sv delim, bool discard_empty = false) noexcept {
		std::vector<std::string_view> result;
		std::size_t i = 0;
		while (true) {
			const std::size_t j = str.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(str.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (str.size() - i)) {
			result.push_back(str.substr(i));
		}
		return result;
	}
}
