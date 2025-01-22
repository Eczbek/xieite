module;

#include <xieite/fwd.hpp>

export module xieite:make_constexpr;

import std;
import :bit_size;
import :repeat;

export namespace xieite {
	constexpr void make_constexpr(auto&& fn, unsigned char x) {
		xieite::repeat<(1uz << xieite::bit_size<char>)>([&fn, x]<std::size_t i> -> void {
			static constexpr auto j = static_cast<unsigned char>(i);
			if (x == j) {
				XIEITE_FWD(fn).template operator()<j>();
			}
		});
	}
}
