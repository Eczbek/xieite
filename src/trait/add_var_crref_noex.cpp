export module xieite:add_var_crref_noex;

import :add_noex;
import :add_var_crref;

export namespace xieite {
	template<typename T>
	using add_var_crref_noex = xieite::add_var_crref<xieite::add_noex<T>>;
}
