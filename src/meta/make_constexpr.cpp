module;

#include <xieite/fwd.hpp>

export module xieite:make_constexpr;

import std;
import :repeat;

export namespace xieite {
	constexpr void make_constexpr(auto&& fn, std::uint8_t value) {
		xieite::repeat<(1uz << std::numeric_limits<std::uint8_t>::digits)>([&fn, value]<std::size_t i> -> void {
			static constexpr std::uint8_t idx = static_cast<std::uint8_t>(i);
			if (value == idx) {
				XIEITE_FWD(fn).template operator()<idx>();
			}
		});
	}
}
