export module xieite:pad;

import std;

export namespace xieite {
	[[nodiscard]] constexpr std::string pad(std::string_view str, std::size_t size, char c = ' ', bool align_front = true) noexcept {
		std::string result = std::string(str);
		result.reserve(size);
		if (str.size() < size) {
			return std::string((size - str.size() + !align_front) / 2, c) + result + std::string((size - str.size() + align_front) / 2, c);
		}
		return result;
	}
}
