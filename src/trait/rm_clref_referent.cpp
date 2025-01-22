export module xieite:rm_clref_referent;

import :rm_c_referent;
import :rm_lref_referent;

export namespace xieite {
	template<typename T>
	using rm_clref_referent = xieite::rm_c_referent<xieite::rm_lref_referent<T>>;
}
