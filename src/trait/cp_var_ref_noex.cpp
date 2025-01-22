export module xieite:cp_var_ref_noex;

import :cp_noex;
import :cp_var_ref;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_ref_noex = xieite::cp_var_ref<T, xieite::cp_noex<T, U>>;
}
