#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> strrplc(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> orig, std::type_identity_t<std::basic_string_view<Ch, Traits>> with, Alloc&& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Ch, Traits, Alloc>(strv, X4FWD(alloc));
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
	[[nodiscard]] constexpr auto strrplc(std::basic_string_view<Ch, Traits> strv, Ch orig, std::type_identity_t<std::basic_string_view<Ch, Traits>> with, Alloc&& alloc = {})
		X4AR(x4::strrplc(strv, x4::strv(orig), with, X4FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strrplc(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> orig, Ch with, Alloc&& alloc = {})
		X4AR(x4::strrplc(strv, orig, x4::strv(with), X4FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strrplc(std::basic_string_view<Ch, Traits> strv, Ch orig, Ch with, Alloc&& alloc = {})
		X4AR(x4::strrplc(strv, x4::strv(orig), x4::strv(with), X4FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strrplc(const std::basic_string<Ch, Traits>& str, auto&& orig, auto&& with, Alloc&& alloc = {})
		X4AR(x4::strrplc(x4::strv(str), X4FWD(orig), X4FWD(with), X4FWD(alloc)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strrplc(const Ch(& str)[n], auto&& orig, auto&& with, Alloc&& alloc = {})
		X4AR(x4::strrplc(x4::strv<Ch, Traits>(str), X4FWD(orig), X4FWD(with), X4FWD(alloc)))
}
