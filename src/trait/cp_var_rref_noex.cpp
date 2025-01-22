export module xieite:cp_var_rref_noex;

import :cp_noex;
import :cp_var_rref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_rref_noex = xieite::cp_var_rref<T, xieite::cp_noex<T, U>>;
}
