export module xieite:cp_var_c;

import :cp_c_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_c = xieite::cp_var<T, xieite::cp_c_referent<T, U>>;
}
