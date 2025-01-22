export module xieite:cp_ref;

import std;
import :add_lref;
import :cp_rref;
import :is_lref;
import :rm_ref;

export namespace xieite {
	template<typename T, typename U>
	using cp_ref = std::conditional_t<xieite::is_lref<T>, xieite::add_lref<U>, xieite::cp_rref<T, xieite::rm_ref<U>>>;
}
