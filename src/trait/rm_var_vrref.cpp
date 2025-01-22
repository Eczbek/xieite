export module xieite:rm_var_vrref;

import :rm_var;
import :rm_vrref_referent;

export namespace xieite {
	template<typename T>
	using rm_var_vrref = xieite::rm_var<xieite::rm_vrref_referent<T>>;
}
