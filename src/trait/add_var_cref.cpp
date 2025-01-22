export module xieite:add_var_cref;

import :add_ref_referent;
import :add_var_c;

export namespace xieite {
	template<typename T, typename U>
	using add_var_cref = xieite::add_var_c<xieite::add_ref_referent<T, U>>;
}
