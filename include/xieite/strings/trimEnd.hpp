#ifndef XIEITE_HEADER_STRINGS_TRIMEND
#	define XIEITE_HEADER_STRINGS_TRIMEND

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <span>
#	include <string>
#	include <vector>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string trimEnd(const std::string& string, const char character) noexcept {
		for (std::size_t i = string.size(); i--;) {
			if (string[i] != character) {
				return string.substr(0, i);
			}
		}
		return "";
	}

	[[nodiscard]]
	constexpr std::string trimEnd(const std::string& string, std::span<const char> characters) noexcept {
		std::array<bool, std::numeric_limits<char>::max() - std::numeric_limits<char>::min() + 1> characterMap;
		for (const char character : characters) {
			characterMap[character - std::numeric_limits<char>::min()] = true;
		}
		for (std::size_t i = string.size(); i--;) {
			if (!characterMap[string[i]]) {
				return string.substr(0, i);
			}
		}
		return "";
	}
}

#endif
