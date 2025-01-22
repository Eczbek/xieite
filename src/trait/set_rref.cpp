export module xieite:set_rref;

import std;
import :add_rref;
import :rm_ref;
import :rm_rref;

export namespace xieite {
	template<bool qual, typename T>
	using set_rref = std::conditional_t<qual, xieite::add_rref<xieite::rm_ref<T>>, xieite::rm_rref<T>>;
}
