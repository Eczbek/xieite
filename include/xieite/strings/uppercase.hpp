#ifndef XIEITE_HEADER_STRINGS_UPPERCASE
#	define XIEITE_HEADER_STRINGS_UPPERCASE

#	include <array>
#	include <limits>
#	include <numeric>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr char uppercase(const char character) noexcept {
		static constexpr auto lookup = ([] -> std::array<char, std::numeric_limits<unsigned char>::max() + 1> {
			std::array<char, std::numeric_limits<unsigned char>::max() + 1> result;
			std::iota(result.begin(), result.end(), 0);
			for (std::size_t i = 0; i < 26; ++i) {
				result[static_cast<unsigned char>("abcdefghijklmnopqrstuvwxyz"[i])] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
			}
			return result;
		})();
		return lookup[static_cast<unsigned char>(character)];
	}

	[[nodiscard]] constexpr std::string uppercase(const std::string_view string) noexcept {
		std::string result = std::string(string);
		for (char& character : result) {
			character = xieite::strings::uppercase(character);
		}
		return result;
	}
}

#endif
