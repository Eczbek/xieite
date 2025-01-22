export module xieite:rm_var_cref;

import :rm_cref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cref = xieite::rm_var<xieite::rm_cref_referent<T>>;
}
