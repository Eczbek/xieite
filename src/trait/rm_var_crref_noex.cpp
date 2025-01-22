export module xieite:rm_var_crref_noex;

import :rm_noex;
import :rm_var_crref;

export namespace xieite {
	template<typename T>
	using rm_var_crref_noex = xieite::rm_var_crref<xieite::rm_noex<T>>;
}
