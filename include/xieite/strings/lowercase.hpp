#ifndef XIEITE_HEADER__STRINGS__LOWERCASE
#	define XIEITE_HEADER__STRINGS__LOWERCASE

#	include <array>
#	include <limits>
#	include <numeric>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr char lowercase(const char character) noexcept {
		static constexpr std::array<char, std::numeric_limits<unsigned char>::max() + 1> lookup = ([] {
			std::array<char, std::numeric_limits<unsigned char>::max() + 1> result;
			std::iota(result.begin(), result.end(), 0);
			for (std::size_t i = 0; i < 26; ++i) {
				result[static_cast<unsigned char>("ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i])] = "abcdefghijklmnopqrstuvwxyz"[i];
			}
			return result;
		})();
		return lookup[static_cast<unsigned char>(character)];
	}

	[[nodiscard]] constexpr std::string lowercase(const std::string_view string) noexcept {
		std::string result = std::string(string);
		for (char& character : result) {
			character = xieite::strings::lowercase(character);
		}
		return result;
	}
}

#endif
