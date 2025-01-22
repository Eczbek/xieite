export module xieite:add_var_vlref_noex;

import :add_noex;
import :add_var_vlref;

export namespace xieite {
	template<typename T>
	using add_var_vlref_noex = xieite::add_var_vlref<xieite::add_noex<T>>;
}
