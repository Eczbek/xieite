export module xieite:rm_cref_referent;

import :rm_clref_referent;
import :rm_rref_referent;

export namespace xieite {
	template<typename T>
	using rm_cref_referent = xieite::rm_clref_referent<xieite::rm_rref_referent<T>>;
}
