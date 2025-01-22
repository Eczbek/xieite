export module xieite:cp_var_vref_noex;

import :cp_noex;
import :cp_var_vref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vref_noex = xieite::cp_var_vref<T, xieite::cp_noex<T, U>>;
}
