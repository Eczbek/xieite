export module xieite:cp_var_cvrref;

import :cp_cvrref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvrref = xieite::cp_var<T, xieite::cp_cvrref_referent<T, U>>;
}
