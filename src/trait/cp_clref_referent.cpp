export module xieite:cp_clref_referent;

import :cp_c_referent;
import :cp_lref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_clref_referent = xieite::cp_c_referent<T, xieite::cp_lref_referent<T, U>>;
}
