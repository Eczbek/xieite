export module xieite:set_ptr;

import std;
import :add_ptr;
import :rm_ptr;

export namespace xieite {
	template<typename T, std::size_t n = 1>
	using set_ptr = xieite::add_ptr<xieite::rm_ptr<T, -1uz>, n>;
}
