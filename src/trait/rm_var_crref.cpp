export module xieite:rm_var_crref;

import :rm_crref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_crref = xieite::rm_var<xieite::rm_crref_referent<T>>;
}
