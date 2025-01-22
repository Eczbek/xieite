export module xieite:rm_lref;

import std;
import :is_lref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_lref = std::conditional_t<xieite::is_lref<T>, xieite::rm_ref<T>, T>;
}
