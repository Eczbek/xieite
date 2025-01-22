export module xieite:rm_var_ref_noex;

import :rm_noex;
import :rm_var_ref;

export namespace xieite {
	template<typename T>
	using rm_var_ref_noex = xieite::rm_var_ref<xieite::rm_noex<T>>;
}
