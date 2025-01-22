export module xieite:rm_cref;

import :rm_c;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_cref = xieite::rm_c<xieite::rm_ref<T>>;
}
