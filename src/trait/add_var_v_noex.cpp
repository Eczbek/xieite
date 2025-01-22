export module xieite:add_var_v_noex;

import :add_noex;
import :add_var_v;

export namespace xieite {
	template<typename T>
	using add_var_v_noex = xieite::add_var_v<xieite::add_noex<T>>;
}
