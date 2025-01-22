export module xieite:rm_var_v;

import :rm_v_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_v = xieite::rm_var<xieite::rm_v_referent<T>>;
}
