#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <numeric>
#include <string>
#include "../ctnr/ch.hpp"
#include "../math/bit_size.hpp"
#include "../math/sign_cast.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr Ch tolower(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << xieite::bit_size<Ch>)>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::ch::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::ch::upper[i])] = static_cast<Ch>(xieite::ch::lower[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Ch, typename Traits, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> tolower(std::basic_string_view<Ch, Traits> strv) noexcept {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv);
		for (Ch& c : result) {
			c = xieite::tolower(c);
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> tolower(Ch* str) noexcept {
		return xieite::tolower<Ch, Traits, Alloc>(std::basic_string_view<Ch, Traits>(str));
	}
}
