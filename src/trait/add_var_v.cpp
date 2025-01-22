export module xieite:add_var_v;

import :add_v_referent;
import :add_var;

export namespace xieite {
	template<typename T>
	using add_var_v = xieite::add_var<xieite::add_v_referent<T>>;
}
