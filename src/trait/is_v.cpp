export module xieite:is_v;

import std;
import :rm_ref;

export namespace xieite {
	template<typename T>
	concept is_v = std::is_volatile_v<xieite::rm_ref<T>>;
}
