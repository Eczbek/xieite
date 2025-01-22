export module xieite:cp_var_clref;

import :cp_clref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_clref = xieite::cp_var<T, xieite::cp_clref_referent<T, U>>;
}
