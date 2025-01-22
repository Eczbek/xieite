export module xieite:rm_crref;

import :rm_c;
import :rm_rref;

export namespace xieite {
	template<typename T>
	using rm_crref = xieite::rm_c<xieite::rm_rref<T>>;
}
