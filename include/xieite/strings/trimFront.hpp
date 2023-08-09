#ifndef XIEITE_HEADER__STRINGS__TRIM_FRONT
#	define XIEITE_HEADER__STRINGS__TRIM_FRONT

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include "../concepts/RangeOf.hpp"

namespace xieite::strings {
	constexpr std::string trimFront(const std::string& string, const char character) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			if (string[i] != character) {
				return string.substr(i);
			}
		}
		return "";
	}

	template<xieite::concepts::RangeOf<char> CharacterRange>
	constexpr std::string trimFront(const std::string& string, const CharacterRange& characters) noexcept {
		std::array<bool, std::numeric_limits<unsigned char>::max() + 1> characterMap;
		for (const char character : characters) {
			characterMap[static_cast<unsigned char>(character)] = true;
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
