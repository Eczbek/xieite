export module xieite:cp_var_v_noex;

import :cp_noex;
import :cp_var_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_v_noex = xieite::cp_var_v<T, xieite::cp_noex<T, U>>;
}
