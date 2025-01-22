export module xieite:cp_var_cref;

import :cp_cref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cref = xieite::cp_var<T, xieite::cp_cref_referent<T, U>>;
}
