export module xieite:cp_var_crref_noex;

import :cp_noex;
import :cp_var_crref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_crref_noex = xieite::cp_var_crref<T, xieite::cp_noex<T, U>>;
}
