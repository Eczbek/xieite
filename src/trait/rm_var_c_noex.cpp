export module xieite:rm_var_c_noex;

import :rm_noex;
import :rm_var_c;

export namespace xieite {
	template<typename T>
	using rm_var_c_noex = xieite::rm_var_c<xieite::rm_noex<T>>;
}
