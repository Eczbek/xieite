export module xieite:rm_var_vrref_noex;

import :rm_noex;
import :rm_var_vrref;

export namespace xieite {
	template<typename T>
	using rm_var_vrref_noex = xieite::rm_var_vrref<xieite::rm_noex<T>>;
}
