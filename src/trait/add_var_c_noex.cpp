export module xieite:add_var_c_noex;

import :add_noex;
import :add_var_c;

export namespace xieite {
	template<typename T>
	using add_var_c_noex = xieite::add_var_c<xieite::add_noex<T>>;
}
