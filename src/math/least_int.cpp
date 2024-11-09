export module xieite:least_int;

import std;
import :least_uint;

export namespace xieite {
	template<std::size_t bits>
	using least_int = std::make_signed_t<xieite::least_uint<bits>>;
}
