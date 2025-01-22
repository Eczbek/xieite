export module xieite:cp_crref_referent;

import :cp_c_referent;
import :cp_rref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_crref_referent = xieite::cp_c_referent<T, xieite::cp_rref_referent<T, U>>;
}
