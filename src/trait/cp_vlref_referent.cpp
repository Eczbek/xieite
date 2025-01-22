export module xieite:cp_vlref_referent;

import :cp_lref_referent;
import :cp_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vlref_referent = xieite::cp_v_referent<T, xieite::cp_lref_referent<T, U>>;
}
