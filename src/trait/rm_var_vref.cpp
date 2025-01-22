export module xieite:rm_var_vref;

import :rm_var;
import :rm_vref_referent;

export namespace xieite {
	template<typename T>
	using rm_var_vref = xieite::rm_var<xieite::rm_vref_referent<T>>;
}
