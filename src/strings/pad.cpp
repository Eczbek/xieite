export module xieite:strings.pad;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string pad(const std::string_view value, const std::size_t size, const char padding = ' ', const bool alignFront = true) noexcept {
		std::string result = std::string(value);
		result.reserve(size);
		const std::size_t valueSize = value.size();
		if (valueSize < size) {
			return std::string((size - valueSize + !alignFront) / 2, padding) + result + std::string((size - valueSize + alignFront) / 2, padding);
		}
		return result;
	}
}
