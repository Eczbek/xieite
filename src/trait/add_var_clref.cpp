export module xieite:add_var_clref;

import :add_lref_referent;
import :add_var_c;

export namespace xieite {
	template<typename T>
	using add_var_clref = xieite::add_var_c<xieite::add_lref_referent<T>>;
}
