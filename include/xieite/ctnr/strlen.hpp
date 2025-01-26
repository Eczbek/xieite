#pragma once

#include <cstddef>
#include "../trait/is_ch.hpp"
#include "../trait/is_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<xieite::is_ptr Str>
	requires(xieite::is_ch<xieite::rm_ptr<Str>>)
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
