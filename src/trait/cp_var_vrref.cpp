export module xieite:cp_var_vrref;

import :cp_var;
import :cp_vrref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vrref = xieite::cp_var<T, xieite::cp_vrref_referent<T, U>>;
}
