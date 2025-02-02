#pragma once

#include <array>
#include <cstddef>

namespace xieite::radix_lit {
	template<char... chars>
	[[nodiscard]] constexpr std::size_t operator""_radix() noexcept {
		if constexpr ((sizeof...(chars) > 1) && (chars...[0] == '0')) {
			switch (chars...[1]) {
			case 'x':
			case 'X':
				return 16;
			case 'b':
			case 'B':
				return 2;
			default:
				return 8;
			}
		} else {
			return 10;
		}
	}
}
