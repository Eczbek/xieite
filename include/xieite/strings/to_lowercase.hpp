#ifndef XIEITE_HEADER_STRINGS_LOWERCASE
#	define XIEITE_HEADER_STRINGS_LOWERCASE

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <numeric>
#	include <string>
#	include "../concepts/character.hpp"
#	include "../concepts/string.hpp"
#	include "../strings/characters.hpp"

namespace xieite::strings {
	template<xieite::concepts::Character Character = char>
	[[nodiscard]] constexpr Character toLowercase(const Character character) noexcept {
		using Lookup = std::array<char, static_cast<std::size_t>(std::numeric_limits<unsigned char>::max()) + 1>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, 0);
			for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
				lookup[static_cast<std::size_t>(static_cast<unsigned char>(xieite::strings::characters::uppercase[i]))] = xieite::strings::characters::lowercase[i];
			}
			return lookup;
		})();
		return static_cast<Character>(lookup[static_cast<std::size_t>(static_cast<unsigned char>(character))]);
	}

	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String toLowercase(String string) noexcept {
		for (String::value_type& character : string) {
			character = xieite::strings::toLowercase(character);
		}
		return string;
	}
}

#endif
