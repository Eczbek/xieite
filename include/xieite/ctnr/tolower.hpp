#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <numeric>
#include <string>
#include <string_view>
#include "../ctnr/ch.hpp"
#include "../ctnr/str_view.hpp"
#include "../math/bit_size.hpp"
#include "../math/sign_cast.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<xieite::is_ch Ch>
	[[nodiscard]] constexpr Ch tolower(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << xieite::bit_size<Ch>)>;
		static constexpr Lookup lookup = ([] static -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::ch::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::ch::upper[i])] = static_cast<Ch>(xieite::ch::lower[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> tolower(std::basic_string_view<Ch, Traits> strv, Alloc&& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv, XIEITE_FWD(alloc));
		for (Ch& c : result) {
			c = xieite::tolower(c);
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto tolower(const std::basic_string<Ch, Traits, Alloc>& str, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::tolower(xieite::str_view(str), XIEITE_FWD(alloc)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto tolower(const xieite::group<Ch[n]>& str, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::tolower(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(alloc)))
}
