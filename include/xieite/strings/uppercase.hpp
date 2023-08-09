#ifndef XIEITE_HEADER__STRINGS__UPPERCASE
#	define XIEITE_HEADER__STRINGS__UPPERCASE

#	include <array>
#	include <limits>
#	include <numeric>
#	include <string>

namespace xieite::strings {
	constexpr char uppercase(const char character) noexcept {
		static constexpr std::array<char, std::numeric_limits<unsigned char>::max() + 1> lookup = ([] {
			std::array<char, std::numeric_limits<unsigned char>::max() + 1> result;
			std::iota(result.begin(), result.end(), 0);
			for (std::size_t i = 0; i < 26; ++i) {
				result[static_cast<unsigned char>("abcdefghijklmnopqrstuvwxyz"[i])] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
			}
			return result;
		})();
		return lookup[static_cast<unsigned char>(character)];
	}

	constexpr std::string uppercase(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::uppercase(character);
		}
		return string;
	}
}

#endif
