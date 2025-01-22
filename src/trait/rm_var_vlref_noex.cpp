export module xieite:rm_var_vlref_noex;

import :rm_noex;
import :rm_var_vlref;

export namespace xieite {
	template<typename T>
	using rm_var_vlref_noex = xieite::rm_var_vlref<xieite::rm_noex<T>>;
}
