export module xieite:set_lref;

import std;
import :add_lref;
import :rm_lref;

export namespace xieite {
	template<bool qual, typename T>
	using set_lref = std::conditional_t<qual, xieite::add_lref<T>, xieite::rm_lref<T>>;
}
