export module xieite:add_var_lref_noex;

import :add_noex;
import :add_var_lref;

export namespace xieite {
	template<typename T>
	using add_var_lref_noex = xieite::add_var_lref<xieite::add_noex<T>>;
}
