export module xieite:cp_var_clref_noex;

import :cp_noex;
import :cp_var_clref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_clref_noex = xieite::cp_var_clref<T, xieite::cp_noex<T, U>>;
}
