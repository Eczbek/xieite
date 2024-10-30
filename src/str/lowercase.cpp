export module xieite:lowercase;

import std;
import :sign_cast;
import :chars;

export namespace xieite {
	[[nodiscard]] constexpr char lowercase(char c) noexcept {
		static constexpr auto lookup = ([] {
			std::array<char, (1uz << std::numeric_limits<unsigned char>::digits)> lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::upper[i])] = xieite::chars::lower[i];
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	[[nodiscard]] constexpr std::string lowercase(std::string_view str) noexcept {
		std::string result = std::string(str);
		for (char& c : result) {
			c = xieite::lowercase(c);
		}
		return result;
	}
}
