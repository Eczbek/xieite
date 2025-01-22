export module xieite:add_var_vref;

import :add_ref_referent;
import :add_var_v;

export namespace xieite {
	template<typename T, typename U>
	using add_var_vref = xieite::add_var_v<xieite::add_ref_referent<T, U>>;
}
