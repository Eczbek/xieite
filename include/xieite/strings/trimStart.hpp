#ifndef XIEITE_HEADER_STRINGS_TRIMSTART
#	define XIEITE_HEADER_STRINGS_TRIMSTART

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <vector>
#	include <xieite/concepts/RangeOf.hpp>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string trimStart(const std::string& string, const char character) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			if (string[i] != character) {
				return string.substr(i);
			}
		}
		return "";
	}

	[[nodiscard]]
	constexpr std::string trimStart(const std::string& string, const xieite::concepts::RangeOf<char> auto& characters) noexcept {
		std::array<char, std::numeric_limits<char>::max() - std::numeric_limits<char>::min() + 1> characterMap;
		for (const char character : characters) {
			characterMap[character - std::numeric_limits<char>::min()] = true;
		}
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			if (!characterMap[string[i]]) {
				return string.substr(i);
			}
		}
		return "";
	}
}

#endif
