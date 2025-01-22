export module xieite:is_c;

import std;
import :rm_ref;

export namespace xieite {
	template<typename T>
	concept is_c = std::is_const_v<xieite::rm_ref<T>>;
}
