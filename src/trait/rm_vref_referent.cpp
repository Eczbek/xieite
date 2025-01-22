export module xieite:rm_vref_referent;

import :rm_ref_referent;
import :rm_v_referent;

export namespace xieite {
	template<typename T>
	using rm_vref_referent = xieite::rm_v_referent<xieite::rm_ref_referent<T>>;
}
