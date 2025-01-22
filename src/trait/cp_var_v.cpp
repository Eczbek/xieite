export module xieite:cp_var_v;

import :cp_v_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_v = xieite::cp_var<T, xieite::cp_v_referent<T, U>>;
}
