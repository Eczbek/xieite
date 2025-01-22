export module xieite:cp_var_cvrref_noex;

import :cp_noex;
import :cp_var_cvrref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvrref_noex = xieite::cp_var_cvrref<T, xieite::cp_noex<T, U>>;
}
