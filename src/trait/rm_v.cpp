export module xieite:rm_v;

import std;
import :cp_ref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_v = xieite::cp_ref<T, std::remove_volatile_t<xieite::rm_ref<T>>>;
}
