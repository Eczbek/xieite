export module xieite:add_var_rref;

import :add_rref_referent;
import :add_var;

export namespace xieite {
	template<typename T>
	using add_var_rref = xieite::add_var<xieite::add_rref_referent<T>>;
}
