export module xieite:is_var_ref_noex;

import :is_noex;
import :is_var_ref;

export namespace xieite {
	template<typename T>
	concept is_var_ref_noex = xieite::is_var_ref<T> && xieite::is_noex<T>;
}
