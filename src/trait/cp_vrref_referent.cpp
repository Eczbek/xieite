export module xieite:cp_vrref_referent;

import :cp_rref_referent;
import :cp_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vrref_referent = xieite::cp_v_referent<T, xieite::cp_rref_referent<T, U>>;
}
