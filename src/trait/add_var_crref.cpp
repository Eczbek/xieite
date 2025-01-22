export module xieite:add_var_crref;

import :add_rref_referent;
import :add_var_c;

export namespace xieite {
	template<typename T>
	using add_var_crref = xieite::add_var_c<xieite::add_rref_referent<T>>;
}
