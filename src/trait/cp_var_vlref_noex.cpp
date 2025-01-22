export module xieite:cp_var_vlref_noex;

import :cp_noex;
import :cp_var_vlref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_vlref_noex = xieite::cp_var_vlref<T, xieite::cp_noex<T, U>>;
}
