export module xieite:replace;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string replace(std::string_view str, xieite::sv orig, xieite::sv replc) noexcept {
		std::string result = str;
		std::size_t i = 0;
		while (true) {
			i = result.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, orig.size(), replc);
			++i;
		}
		return result;
	}
}
