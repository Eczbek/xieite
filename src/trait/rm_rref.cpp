export module xieite:rm_rref;

import std;
import :is_rref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_rref = std::conditional_t<xieite::is_rref<T>, xieite::rm_ref<T>, T>;
}
