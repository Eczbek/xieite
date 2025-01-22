export module xieite:cp_var_lref_noex;

import :cp_noex;
import :cp_var_lref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_lref_noex = xieite::cp_var_lref<T, xieite::cp_noex<T, U>>;
}
