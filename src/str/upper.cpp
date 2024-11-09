export module xieite:upper;

import std;
import :bit_size;
import :chars;
import :is_char;
import :sign_cast;

export namespace xieite {
	template<xieite::is_char Ch = char>
	[[nodiscard]] constexpr Ch upper(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << xieite::bit_size<Ch>)>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::lower[i])] = static_cast<Ch>(xieite::chars::upper[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> upper(std::basic_string<Ch, Traits, Alloc> str) noexcept {
		for (Ch& c : str) {
			c = xieite::upper(c);
		}
		return str;
	}
}
