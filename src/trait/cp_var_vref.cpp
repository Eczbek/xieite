export module xieite:cp_var_vref;

import :cp_var;
import :cp_vref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vref = xieite::cp_var<T, xieite::cp_vref_referent<T, U>>;
}
