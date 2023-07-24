#ifndef XIEITE_HEADER_STRINGS_TRIMBACK
#	define XIEITE_HEADER_STRINGS_TRIMBACK

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <xieite/concepts/RangeOf.hpp>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string trimBack(const std::string& string, const char character) noexcept {
		for (std::size_t i = string.size(); i--;) {
			if (string[i] != character) {
				return string.substr(0, i);
			}
		}
		return "";
	}

	template<xieite::concepts::RangeOf<char> CharacterRange>
	[[nodiscard]]
	constexpr std::string trimBack(const std::string& string, const CharacterRange& characters) noexcept {
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
