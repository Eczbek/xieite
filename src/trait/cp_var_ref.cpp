export module xieite:cp_var_ref;

import :cp_ref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_ref = xieite::cp_var<T, xieite::cp_ref_referent<T, U>>;
}
