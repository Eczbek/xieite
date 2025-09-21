#ifndef DETAIL_XIEITE_HEADER_DATA_ISLOWER
#	define DETAIL_XIEITE_HEADER_DATA_ISLOWER
#
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool islower(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'):
			return true;
		}
		return false;
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool islower(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::islower(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool islower(const std::basic_string<Char, Traits, Alloc>& str) noexcept {
		return xieite::islower(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool islower(const xieite::type<Char[length]>& str) noexcept {
		return xieite::islower(xieite::make_str_view(str));
	}
}

#endif
