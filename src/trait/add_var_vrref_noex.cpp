export module xieite:add_var_vrref_noex;

import :add_noex;
import :add_var_vrref;

export namespace xieite {
	template<typename T>
	using add_var_vrref_noex = xieite::add_var_vrref<xieite::add_noex<T>>;
}
