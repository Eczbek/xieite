export module xieite:cp_var_lref;

import :cp_lref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_lref = xieite::cp_var<T, xieite::cp_lref_referent<T, U>>;
}
