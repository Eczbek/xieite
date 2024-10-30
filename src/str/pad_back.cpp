export module xieite:pad_back;

import std;

export namespace xieite {
	[[nodiscard]] constexpr std::string pad_back(std::string_view str, std::size_t size, char c = ' ') noexcept {
		std::string result = std::string(str);
		result.reserve(size);
		if (str.size() < size) {
			result += std::string(size - str.size(), c);
		}
		return result;
	}
}
