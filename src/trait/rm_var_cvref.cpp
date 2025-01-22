export module xieite:rm_var_cvref;

import :rm_cvref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cvref = xieite::rm_var<xieite::rm_cvref_referent<T>>;
}
