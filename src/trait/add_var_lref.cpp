export module xieite:add_var_lref;

import :add_lref_referent;
import :add_var;

export namespace xieite {
	template<typename T>
	using add_var_lref = xieite::add_var<xieite::add_lref_referent<T>>;
}
