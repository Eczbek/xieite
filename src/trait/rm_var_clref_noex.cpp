export module xieite:rm_var_clref_noex;

import :rm_noex;
import :rm_var_clref;

export namespace xieite {
	template<typename T>
	using rm_var_clref_noex = xieite::rm_var_clref<xieite::rm_noex<T>>;
}
