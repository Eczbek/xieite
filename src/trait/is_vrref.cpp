export module xieite:is_vrref;

import :is_rref;
import :is_v;
import :rm_ref;

export namespace xieite {
	template<typename T>
	concept is_vrref = xieite::is_rref<T> && xieite::is_v<xieite::rm_ref<T>>;
}
