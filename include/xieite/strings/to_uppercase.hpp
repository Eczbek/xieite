#ifndef XIEITE_HEADER_STRINGS_UPPERCASE
#	define XIEITE_HEADER_STRINGS_UPPERCASE

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <numeric>
#	include <string>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr char toUppercase(const char character) noexcept {
		using Lookup = std::array<char, static_cast<std::size_t>(std::numeric_limits<unsigned char>::max()) + 1>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, 0);
			for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
				lookup[static_cast<std::size_t>(static_cast<unsigned char>(xieite::strings::characters::lowercase[i]))] = xieite::strings::characters::uppercase[i];
			}
			return lookup;
		})();
		return lookup[static_cast<std::size_t>(static_cast<unsigned char>(character))];
	}

	[[nodiscard]] constexpr std::string toUppercase(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::toUppercase(character);
		}
		return string;
	}
}

#endif
