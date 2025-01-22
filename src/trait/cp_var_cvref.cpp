export module xieite:cp_var_cvref;

import :cp_cvref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvref = xieite::cp_var<T, xieite::cp_cvref_referent<T, U>>;
}
