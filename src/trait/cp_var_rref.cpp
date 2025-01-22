export module xieite:cp_var_rref;

import :cp_rref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_rref = xieite::cp_var<T, xieite::cp_rref_referent<T, U>>;
}
