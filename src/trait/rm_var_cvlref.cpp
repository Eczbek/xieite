export module xieite:rm_var_cvlref;

import :rm_cvlref_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cvlref = xieite::rm_var<xieite::rm_cvlref_referent<T>>;
}
