export module xieite:uppercase;

import std;
import :bit_size;
import :ch;
import :is_ch;
import :sign_cast;

export namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr Ch uppercase(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << xieite::bit_size<Ch>)>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::ch::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::ch::lower[i])] = static_cast<Ch>(xieite::ch::upper[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> uppercase(std::basic_string_view<Ch, Traits> strv) noexcept {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv);
		for (Ch& c : result) {
			c = xieite::uppercase(c);
		}
		return result;
	}
}
