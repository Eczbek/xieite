#ifndef XIEITE_HEADER__STRINGS__TRIM_BACK
#	define XIEITE_HEADER__STRINGS__TRIM_BACK

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include "../concepts/RangeOf.hpp"

namespace xieite::strings {
	constexpr std::string trimBack(const std::string& string, const char character) noexcept {
		for (std::size_t i = string.size(); i--;) {
			if (string[i] != character) {
				return string.substr(0, i);
			}
		}
		return "";
	}

	template<xieite::concepts::RangeOf<char> CharacterRange>
	constexpr std::string trimBack(const std::string& string, const CharacterRange& characters) noexcept {
		std::array<bool, std::numeric_limits<unsigned char>::max() + 1> characterMap;
		for (const char character : characters) {
			characterMap[static_cast<unsigned char>(character)] = true;
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
