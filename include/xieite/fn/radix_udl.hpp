#ifndef DETAIL_XIEITE_HEADER_FN_RADIX_UDL
#	define DETAIL_XIEITE_HEADER_FN_RADIX_UDL
#
#	include <cstddef>

namespace xieite::radix_udl {
	template<char... chars>
	[[nodiscard]] consteval std::size_t operator""_radix() noexcept {
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

#endif
