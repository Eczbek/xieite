export module xieite:add_var_cref_noex;

import :add_noex;
import :add_var_cref;

export namespace xieite {
	template<typename T, typename U>
	using add_var_cref_noex = xieite::add_var_cref<T, xieite::add_noex<U>>;
}
