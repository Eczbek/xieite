export module xieite:cp_var_vrref_noex;

import :cp_noex;
import :cp_var_vrref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vrref_noex = xieite::cp_var_vrref<T, xieite::cp_noex<T, U>>;
}
