export module xieite:rm_var_lref;

import :rm_lref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_lref = xieite::rm_var<xieite::rm_lref_referent<T>>;
}
