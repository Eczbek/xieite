export module xieite:rm_var_cref_noex;

import :rm_noex;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cref_noex = xieite::rm_var_cref<xieite::rm_noex<T>>;
}
