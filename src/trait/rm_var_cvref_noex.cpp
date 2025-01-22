export module xieite:rm_var_cvref_noex;

import :rm_noex;
import :rm_var_cvref;

export namespace xieite {
	template<typename T>
	using rm_var_cvref_noex = xieite::rm_var_cvref<xieite::rm_noex<T>>;
}
