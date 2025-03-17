#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/str_view.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_replace(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> orig, std::type_identity_t<std::basic_string_view<Ch, Traits>> with, Alloc&& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv, XIEITE_FWD(alloc));
		std::size_t i = 0;
		while (true) {
			i = result.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, orig.size(), with);
			++i;
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_replace(std::basic_string_view<Ch, Traits> strv, Ch orig, std::type_identity_t<std::basic_string_view<Ch, Traits>> with, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_replace(strv, xieite::str_view(orig), with, XIEITE_FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_replace(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> orig, Ch with, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_replace(strv, orig, xieite::str_view(with), XIEITE_FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_replace(std::basic_string_view<Ch, Traits> strv, Ch orig, Ch with, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_replace(strv, xieite::str_view(orig), xieite::str_view(with), XIEITE_FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_replace(const std::basic_string<Ch, Traits>& str, auto&& orig, auto&& with, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_replace(xieite::str_view(str), XIEITE_FWD(orig), XIEITE_FWD(with), XIEITE_FWD(alloc)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_replace(const xieite::group<Ch[n]>& str, auto&& orig, auto&& with, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_replace(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(orig), XIEITE_FWD(with), XIEITE_FWD(alloc)))
}
