export module xieite:add_var_vref_noex;

import :add_noex;
import :add_var_vref;

export namespace xieite {
	template<typename T, typename U>
	using add_var_vref_noex = xieite::add_var_vref<T, xieite::add_noex<U>>;
}
