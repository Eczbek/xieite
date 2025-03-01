#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <numeric>
#include <string>
#include <string_view>
#include "../ctnr/ch.hpp"
#include "../ctnr/strv.hpp"
#include "../math/bits.hpp"
#include "../math/sgncast.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<x4::isch Ch>
	[[nodiscard]] constexpr Ch tolower(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << x4::bits<Ch>)>;
		static constexpr Lookup lookup = ([] static -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < x4::ch::alphabetsz; ++i) {
				lookup[x4::sgncast<std::size_t>(x4::ch::upper[i])] = static_cast<Ch>(x4::ch::lower[i]);
			}
			return lookup;
		})();
		return lookup[x4::sgncast<std::size_t>(c)];
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> tolower(std::basic_string_view<Ch, Traits> strv, Alloc&& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv, X4FWD(alloc));
		for (Ch& c : result) {
			c = x4::tolower(c);
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto tolower(const std::basic_string<Ch, Traits, Alloc>& str, Alloc&& alloc = {})
		X4AR(x4::tolower(x4::strv(str), X4FWD(alloc)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto tolower(const Ch(& str)[n], Alloc&& alloc = {})
		X4AR(x4::tolower(x4::strv<Ch, Traits>(str), X4FWD(alloc)))
}
