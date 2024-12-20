module;

#include <xieite/fwd.hpp>

export module xieite:make_constexpr;

import std;
import :bit_size;
import :repeat;

export namespace xieite {
	constexpr void make_constexpr(auto&& fn, std::uint8_t value) {
		xieite::repeat<(1uz << xieite::bit_size<std::uint8_t>)>([&fn, value]<std::size_t i> -> void {
			static constexpr std::uint8_t idx = static_cast<std::uint8_t>(i);
			if (value == idx) {
				XIEITE_FWD(fn).template operator()<idx>();
			}
		});
	}
}
