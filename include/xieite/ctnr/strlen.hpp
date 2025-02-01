#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../trait/is_ch.hpp"
#include "../trait/rm_ptr.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(std::basic_string_view<Ch> strv) noexcept {
		return strv.size();
	}

	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(const std::basic_string<Ch>& str) noexcept {
		return str.size();
	}

	template<xieite::is_ch Ch, std::size_t n>
	[[nodiscard]] constexpr std::size_t strlen(const Ch(&)[n]) noexcept {
		return n - !!n;
	}

	template<xieite::is_ch Ch, typename Str>
	requires(std::same_as<Ch, xieite::rm_ptr<xieite::rm_ref<Str>>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t i = 0;
		while (str && str[i]) {
			++i;
		}
		return i;
	}

	template<xieite::is_ch Ch>
	[[nodiscard]] constexpr std::size_t strlen(Ch) noexcept {
		return 1;
	}
}
