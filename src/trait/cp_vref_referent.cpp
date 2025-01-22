export module xieite:cp_vref_referent;

import :cp_ref_referent;
import :cp_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vref_referent = xieite::cp_v_referent<T, xieite::cp_ref_referent<T, U>>;
}
