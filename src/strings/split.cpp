export module xieite:strings.split;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const std::string_view delimiter, const bool discardEmpty = false) noexcept {
		std::vector<std::string_view> result;
		std::size_t i = 0;
		while (true) {
			const std::size_t j = string.find(delimiter, i);
			if (j == std::string_view::npos) {
				break;
			}
			if (!discardEmpty || (j - i)) {
				result.push_back(string.substr(i, j - i));
			}
			i = j + delimiter.size();
		}
		if (!discardEmpty || (string.size() - i)) {
			result.push_back(string.substr(i));
		}
		return result;
	}

	[[nodiscard]] constexpr std::vector<std::string_view> split(const std::string_view string, const char delimiter, const bool discardEmpty = false) noexcept {
		return xieite::strings::split(string, std::string_view(&delimiter, 1), discardEmpty);
	}
}
