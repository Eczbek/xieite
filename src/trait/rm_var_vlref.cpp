export module xieite:rm_var_vlref;

import :rm_var;
import :rm_vlref_referent;

export namespace xieite {
	template<typename T>
	using rm_var_vlref = xieite::rm_var<xieite::rm_vlref_referent<T>>;
}
