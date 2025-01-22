export module xieite:rm_vrref_referent;

import :rm_rref_referent;
import :rm_v_referent;

export namespace xieite {
	template<typename T>
	using rm_vrref_referent = xieite::rm_v_referent<xieite::rm_rref_referent<T>>;
}
