export module xieite:rm_var_lref_noex;

import :rm_noex;
import :rm_var_lref;

export namespace xieite {
	template<typename T>
	using rm_var_lref_noex = xieite::rm_var_lref<xieite::rm_noex<T>>;
}
