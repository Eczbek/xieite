#ifndef DETAIL_XIEITE_HEADER_DATA_TOUPPER
#	define DETAIL_XIEITE_HEADER_DATA_TOUPPER
#
#	include <array>
#	include <cstddef>
#	include <memory>
#	include <numeric>
#	include <string>
#	include <string_view>
#	include "../data/chars.hpp"
#	include "../data/str_view.hpp"
#	include "../math/bit_size.hpp"
#	include "../math/sign_cast.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char>
	[[nodiscard]] constexpr Char toupper(Char c) noexcept {
		using Lookup = std::array<Char, (1uz << xieite::bit_size<Char>)>;
		static constexpr Lookup lookup = ([] static -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::lower[i])] = static_cast<Char>(xieite::chars::upper[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> toupper(std::basic_string_view<Char, Traits> strv, const Alloc& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Char, Traits, Alloc>(strv, alloc);
		for (Char& c : result) {
			c = xieite::toupper(c);
		}
		return result;
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto toupper(const std::basic_string<Char, Traits, Alloc>& str, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::toupper(xieite::str_view(str), alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto toupper(const xieite::paren<Char[length]>& str, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::toupper(xieite::str_view<Char, Traits>(str), alloc))
}

#endif
