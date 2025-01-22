export module xieite:cp_var_cvref_noex;

import :cp_noex;
import :cp_var_cvref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvref_noex = xieite::cp_var_cvref<T, xieite::cp_noex<T, U>>;
}
