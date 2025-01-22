export module xieite:rm_var_v_noex;

import :rm_noex;
import :rm_var_v;

export namespace xieite {
	template<typename T>
	using rm_var_v_noex = xieite::rm_var_v<xieite::rm_noex<T>>;
}
