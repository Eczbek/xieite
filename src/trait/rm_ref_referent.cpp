export module xieite:rm_ref_referent;

import :rm_lref_referent;
import :rm_rref_referent;

export namespace xieite {
	template<typename T>
	using rm_ref_referent = xieite::rm_lref_referent<xieite::rm_rref_referent<T>>;
}
