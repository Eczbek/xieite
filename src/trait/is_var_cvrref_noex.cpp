export module xieite:is_var_cvrref_noex;

import :is_noex;
import :is_var_cvrref;

export namespace xieite {
	template<typename T>
	concept is_var_cvrref_noex = xieite::is_var_cvrref<T> && xieite::is_noex<T>;
}
