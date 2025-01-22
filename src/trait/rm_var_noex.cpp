export module xieite:rm_var_noex;

import :rm_noex;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_noex = xieite::rm_var<xieite::rm_noex<T>>;
}
