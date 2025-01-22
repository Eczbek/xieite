export module xieite:rm_clref;

import :rm_c;
import :rm_lref;

export namespace xieite {
	template<typename T>
	using rm_clref = xieite::rm_c<xieite::rm_lref<T>>;
}
