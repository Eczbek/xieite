export module xieite:str_repeat;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string str_repeat(std::size_t n, xieite::sv<> str) noexcept {
		std::string result;
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}
}
