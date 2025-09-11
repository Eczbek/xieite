#ifndef DETAIL_XIEITE_HEADER_META_MAKE_CXPR
#	define DETAIL_XIEITE_HEADER_META_MAKE_CXPR
#
#	include <cstddef>
#	include "../fn/repeat.hpp"
#	include "../math/bit_size.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	constexpr void make_cxpr(auto&& fn, unsigned char x) {
		xieite::repeat<(1uz << xieite::bit_size<char>)>([&fn, x]<std::size_t i> -> void {
			if (x == static_cast<unsigned char>(i)) {
				XIEITE_FWD(fn).template operator()<static_cast<unsigned char>(i)>();
			}
		});
	}
}

#endif
