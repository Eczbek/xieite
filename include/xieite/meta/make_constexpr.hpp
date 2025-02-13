#pragma once

#include <cstddef>
#include "../fn/repeat.hpp"
#include "../math/bit_size.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	constexpr void make_constexpr(auto&& fn, unsigned char x) {
		xieite::repeat<(1uz << xieite::bit_size<char>)>([&fn, x]<std::size_t i> -> void {
			static constexpr auto j = static_cast<unsigned char>(i);
			if (x == j) {
				XIEITE_FWD(fn).template operator()<j>();
			}
		});
	}
}
