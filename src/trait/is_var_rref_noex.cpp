export module xieite:is_var_rref_noex;

import :is_noex;
import :is_var_rref;

export namespace xieite {
	template<typename T>
	concept is_var_rref_noex = xieite::is_var_rref<T> && xieite::is_noex<T>;
}
