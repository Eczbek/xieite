export module xieite:is_var_vref_noex;

import :is_noex;
import :is_var_vref;

export namespace xieite {
	template<typename T>
	concept is_var_vref_noex = xieite::is_var_vref<T> && xieite::is_noex<T>;
}
