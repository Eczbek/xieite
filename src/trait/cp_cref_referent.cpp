export module xieite:cp_cref_referent;

import :cp_c_referent;
import :cp_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_cref_referent = xieite::cp_c_referent<T, xieite::cp_ref_referent<T, U>>;
}
