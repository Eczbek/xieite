#ifndef DETAIL_XTE_HEADER_LITERAL_RADIX
#	define DETAIL_XTE_HEADER_LITERAL_RADIX
#
#	include "../util/types.hpp"

namespace xte::literal::radix {
	template<char... chars>
	[[nodiscard]] consteval xte::uz operator""_radix() noexcept {
		if constexpr ((sizeof...(chars) > 1) && (chars...[0] == '0')) {
			switch (chars...[1]) {
				case 'X': case 'x':
					return 16;
				case 'B': case 'b':
					return 2;
			}
			return 8;
		}
		return 10;
	}
}

#endif
