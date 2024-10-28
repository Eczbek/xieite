export module xieite:repeat;

import std;

export namespace xieite {
	[[nodiscard]] constexpr std::string repeat(std::size_t n, std::string_view str) noexcept {
		std::string result;
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}
}
