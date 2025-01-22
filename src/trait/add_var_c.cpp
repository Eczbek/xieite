export module xieite:add_var_c;

import :add_c_referent;
import :add_var;

export namespace xieite {
	template<typename T>
	using add_var_c = xieite::add_var<xieite::add_c_referent<T>>;
}
