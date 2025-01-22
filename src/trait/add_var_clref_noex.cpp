export module xieite:add_var_clref_noex;

import :add_noex;
import :add_var_clref;

export namespace xieite {
	template<typename T>
	using add_var_clref_noex = xieite::add_var_clref<xieite::add_noex<T>>;
}
