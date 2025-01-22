export module xieite:rm_vlref;

import :cp_lref;
import :rm_v;

export namespace xieite {
	template<typename T>
	using rm_vlref = xieite::rm_v<xieite::rm_lref<T>>;
}
