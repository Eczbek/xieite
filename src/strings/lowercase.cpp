export module xieite:strings.lowercase;

import std;
import :math.signCast;
import :strings.characters;

export namespace xieite::strings {
	[[nodiscard]] constexpr char lowercase(const char character) noexcept {
		using Lookup = std::array<char, (1uz << std::numeric_limits<unsigned char>::digits)>;
		static constexpr Lookup lookup = ([] {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
				lookup[xieite::math::signCast<std::size_t>(xieite::strings::characters::uppercase[i])] = xieite::strings::characters::lowercase[i];
			}
			return lookup;
		})();
		return lookup[xieite::math::signCast<std::size_t>(character)];
	}

	[[nodiscard]] constexpr std::string lowercase(const std::string_view string) noexcept {
		std::string result = std::string(string);
		for (char& character : result) {
			character = xieite::strings::lowercase(character);
		}
		return result;
	}
}
