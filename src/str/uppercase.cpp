export module xieite:uppercase;

import std;
import :chars;
import :sign_cast;

export namespace xieite {
	[[nodiscard]] constexpr char uppercase(char c) noexcept {
		static constexpr auto lookup = ([] {
			std::array<char, (1uz << std::numeric_limits<unsigned char>::digits)> lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::lower[i])] = xieite::chars::upper[i];
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	[[nodiscard]] constexpr std::string uppercase(std::string_view str) noexcept {
		std::string result = std::string(str);
		for (char& c : result) {
			c = xieite::uppercase(c);
		}
		return result;
	}
}
