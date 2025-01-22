export module xieite:cp_var_cvlref;

import :cp_cvlref_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cvlref = xieite::cp_var<T, xieite::cp_cvlref_referent<T, U>>;
}
