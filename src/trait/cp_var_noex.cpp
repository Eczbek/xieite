export module xieite:cp_var_noex;

import :cp_noex;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_noex = xieite::cp_var<T, xieite::cp_noex<T, U>>;
}
