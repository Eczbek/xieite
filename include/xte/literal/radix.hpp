#ifndef DETAIL_XTE_HEADER_LITERAL_RADIX
#	define DETAIL_XTE_HEADER_LITERAL_RADIX
#
#	include "../util/numbers.hpp"

namespace xte::literal::radix {
	template<char... digits>
	requires(!!sizeof...(digits))
	[[nodiscard]] consteval xte::uz operator""_radix() noexcept {
		if constexpr (digits...[0] == '0') {
			if constexpr (sizeof...(digits) > 1) {
				switch (digits...[1]) {
					case 'X': case 'x':
						return 16;
					case 'B': case 'b':
						return 2;
				}
			}
			return 8;
		}
		return 10;
	}
}

#endif
