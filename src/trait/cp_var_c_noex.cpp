export module xieite:cp_var_c_noex;

import :cp_noex;
import :cp_var_c;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_c_noex = xieite::cp_var_c<T, xieite::cp_noex<T, U>>;
}
