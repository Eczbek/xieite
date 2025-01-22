export module xieite:add_var_cvrref_noex;

import :add_noex;
import :add_var_cvrref;

export namespace xieite {
	template<typename T>
	using add_var_cvrref_noex = xieite::add_var_cvrref<xieite::add_noex<T>>;
}
