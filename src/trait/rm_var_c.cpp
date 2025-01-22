export module xieite:rm_var_c;

import :rm_c_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_c = xieite::rm_var<xieite::rm_c_referent<T>>;
}
