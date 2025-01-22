export module xieite:add_var_vrref;

import :add_rref_referent;
import :add_var_v;

export namespace xieite {
	template<typename T>
	using add_var_vrref = xieite::add_var_v<xieite::add_rref_referent<T>>;
}
