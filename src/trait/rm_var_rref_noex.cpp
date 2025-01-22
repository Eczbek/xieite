export module xieite:rm_var_rref_noex;

import :rm_noex;
import :rm_var_rref;

export namespace xieite {
	template<typename T>
	using rm_var_rref_noex = xieite::rm_var_rref<xieite::rm_noex<T>>;
}
