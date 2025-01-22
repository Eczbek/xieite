export module xieite:add_var_vlref;

import :add_lref_referent;
import :add_var_v;

export namespace xieite {
	template<typename T>
	using add_var_vlref = xieite::add_var_v<xieite::add_lref_referent<T>>;
}
