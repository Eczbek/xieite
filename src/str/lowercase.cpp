export module xieite:lowercase;

import std;
import :bit_size;
import :chars;
import :is_char;
import :sign_cast;

export namespace xieite {
	template<xieite::is_char C = char>
	[[nodiscard]] constexpr C lowercase(C c) noexcept {
		static constexpr auto lookup = ([] {
			std::array<C, (1uz << xieite::bit_size<C>)> lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::upper[i])] = static_cast<C>(xieite::chars::lower[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> lowercase(std::basic_string_view<C, Traits> str) noexcept {
		auto result = std::basic_string<C, Traits, Alloc>(str);
		for (C& c : result) {
			c = xieite::lowercase(c);
		}
		return result;
	}
}
