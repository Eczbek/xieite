export module xieite:rm_var_ref;

import :rm_ref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_ref = xieite::rm_var<xieite::rm_ref_referent<T>>;
}
