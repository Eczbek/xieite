export module xieite:rm_crref_referent;

import :rm_c_referent;
import :rm_rref_referent;

export namespace xieite {
	template<typename T>
	using rm_crref_referent = xieite::rm_c_referent<xieite::rm_rref_referent<T>>;
}
