#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr std::vector<std::basic_string_view<Ch, Traits>, VecAlloc> strsplit(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> delim, bool discard_empty = false, VecAlloc&& vec_alloc = {}) noexcept(false) {
		auto result = std::vector<std::basic_string_view<Ch, Traits>, VecAlloc>(X4FWD(vec_alloc));
		std::size_t i = 0;
		while (true) {
			const std::size_t j = strv.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(strv.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (strv.size() - i)) {
			result.push_back(strv.substr(i));
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr auto strsplit(std::basic_string_view<Ch, Traits> strv, Ch delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		X4AR(x4::strsplit(strv, x4::strv(delim), discard_empty, X4FWD(vec_alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr auto strsplit(const std::basic_string<Ch, Traits>& str, auto&& delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		X4AR(x4::strsplit(x4::strv(str), X4FWD(delim), discard_empty, X4FWD(vec_alloc)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>, std::size_t n>
	[[nodiscard]] constexpr auto strsplit(const Ch(& str)[n], auto&& delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		X4AR(x4::strsplit(x4::strv<Ch, Traits>(str), X4FWD(delim), discard_empty, X4FWD(vec_alloc)))
}
