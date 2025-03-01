#pragma once

#include <cstddef>
#include "../fn/rpt.hpp"
#include "../math/bits.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	constexpr void mkcxpr(auto&& fn, unsigned char x) {
		x4::rpt<(1uz << x4::bits<char>)>([&fn, x]<std::size_t i> -> void {
			static constexpr auto j = static_cast<unsigned char>(i);
			if (x == j) {
				X4FWD(fn).template operator()<j>();
			}
		});
	}
}
