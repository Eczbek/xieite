export module xieite:rm_var_clref;

import :rm_clref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_clref = xieite::rm_var<xieite::rm_clref_referent<T>>;
}
