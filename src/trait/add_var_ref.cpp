export module xieite:add_var_ref;

import :add_ref_referent;
import :add_var;

export namespace xieite {
	template<typename T, typename U>
	using add_var_ref = xieite::add_var<xieite::add_ref_referent<T, U>>;
}
