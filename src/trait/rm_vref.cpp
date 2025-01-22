export module xieite:rm_vref;

import :rm_ref;
import :rm_v;

export namespace xieite {
	template<typename T>
	concept rm_vref = xieite::rm_v<xieite::rm_ref<T>>;
}
