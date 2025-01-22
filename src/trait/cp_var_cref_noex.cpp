export module xieite:cp_var_cref_noex;

import :cp_noex;
import :cp_var_cref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cref_noex = xieite::cp_var_cref<T, xieite::cp_noex<T, U>>;
}
