export module xieite:is_var_cref_noex;

import :is_noex;
import :is_var_cref;

export namespace xieite {
	template<typename T>
	concept is_var_cref_noex = xieite::is_var_cref<T> && xieite::is_noex<T>;
}
