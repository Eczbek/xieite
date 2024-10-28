export module xieite:pad_front;

import std;

export namespace xieite {
	[[nodiscard]] constexpr std::string pad_front(std::string_view str, std::size_t size, char c = ' ') noexcept {
		std::string result = std::string(str);
		result.reserve(size);
		if (str.size() < size) {
			return std::string(size - str.size(), c) + result;
		}
		return result;
	}
}
