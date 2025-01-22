export module xieite:rm_var_vref_noex;

import :rm_noex;
import :rm_var_vref;

export namespace xieite {
	template<typename T>
	using rm_var_vref_noex = xieite::rm_var_vref<xieite::rm_noex<T>>;
}
