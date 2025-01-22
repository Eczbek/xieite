export module xieite:cp_var_vlref;

import :cp_var;
import :cp_vlref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vlref = xieite::cp_var<T, xieite::cp_vlref_referent<T, U>>;
}
