export module xieite:rm_c;

import std;
import :cp_ref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_c = xieite::cp_ref<T, std::remove_const_t<xieite::rm_ref<T>>>;
}
