export module xieite:add_var_cvrref;

import :add_rref_referent;
import :add_var_cv;

export namespace xieite {
	template<typename T>
	using add_var_cvrref = xieite::add_var_cv<xieite::add_rref_referent<T>>;
}
