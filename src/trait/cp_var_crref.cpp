export module xieite:cp_var_crref;

import :cp_crref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_crref = xieite::cp_var<T, xieite::cp_crref_referent<T, U>>;
}
