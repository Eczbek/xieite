export module xieite:rm_var_cvrref;

import :rm_cvrref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cvrref = xieite::rm_var<xieite::rm_cvrref_referent<T>>;
}
