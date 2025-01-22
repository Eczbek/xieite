export module xieite:cp_var_cvlref_noex;

import :cp_noex;
import :cp_var_cvlref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvlref_noex = xieite::cp_var_cvlref<T, xieite::cp_noex<T, U>>;
}
