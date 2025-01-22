export module xieite:is_var_lref_noex;

import :is_noex;
import :is_var_lref;

export namespace xieite {
	template<typename T>
	concept is_var_lref_noex = xieite::is_var_lref<T> && xieite::is_noex<T>;
}
