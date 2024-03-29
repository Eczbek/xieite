#ifndef XIEITE_HEADER_STRINGS_LOWERCASE
#	define XIEITE_HEADER_STRINGS_LOWERCASE

#	include <array>
#	include <cstddef>
#	include <limits>
#	include <numeric>
#	include <string>
#	include "../math/sign_cast.hpp"
#	include "../strings/characters.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr char toUppercase(const char character) noexcept {
		using Lookup = std::array<char, static_cast<std::size_t>(std::numeric_limits<unsigned char>::max()) + 1>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::iota(lookup.begin(), lookup.end(), 0); // TODO: Replace with std::ranges::iota
			for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
				lookup[xieite::math::signCast<std::size_t>(xieite::strings::characters::lowercase[i])] = xieite::strings::characters::uppercase[i];
			}
			return lookup;
		})();
		return lookup[xieite::math::signCast<std::size_t>(character)];
	}

	[[nodiscard]] constexpr std::string toUppercase(const std::string_view string) noexcept {
		std::string result = std::string(string);
		for (char& character : result) {
			character = xieite::strings::toUppercase(character);
		}
		return result;
	}
}

#endif
