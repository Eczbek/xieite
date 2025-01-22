export module xieite:rm_var_rref;

import :rm_rref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_rref = xieite::rm_var<xieite::rm_rref_referent<T>>;
}
