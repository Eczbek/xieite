export module xieite:is_var_crref_noex;

import :is_noex;
import :is_var_crref;

export namespace xieite {
	template<typename T>
	concept is_var_crref_noex = xieite::is_var_crref<T> && xieite::is_noex<T>;
}
