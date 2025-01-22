export module xieite:is_var_clref_noex;

import :is_noex;
import :is_var_clref;

export namespace xieite {
	template<typename T>
	concept is_var_clref_noex = xieite::is_var_clref<T> && xieite::is_noex<T>;
}
