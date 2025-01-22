export module xieite:rm_var_cvrref_noex;

import :rm_noex;
import :rm_var_cvrref;

export namespace xieite {
	template<typename T>
	using rm_var_cvrref_noex = xieite::rm_var_cvrref<xieite::rm_noex<T>>;
}
