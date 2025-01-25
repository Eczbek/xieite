#pragma once

#include <cstddef>
#include <type_traits>
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Str>
	requires(std::is_pointer_v<Str> && xieite::is_ch<std::remove_pointer_t<Str>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t size = 0;
		while (str[size]) {
			++size;
		}
		return size;
	}

	template<xieite::is_ch Ch, std::size_t size>
	[[nodiscard]] constexpr std::size_t strlen(Ch(&)[size]) noexcept {
		return size - 1;
	}
}
