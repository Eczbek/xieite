export module xieite:is_vlref;

import :is_lref;
import :is_v;
import :rm_ref;

export namespace xieite {
	template<typename T>
	concept is_vlref = xieite::is_lref<T> && xieite::is_v<xieite::rm_ref<T>>;
}
