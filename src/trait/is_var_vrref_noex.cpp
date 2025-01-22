export module xieite:is_var_vrref_noex;

import :is_noex;
import :is_var_vrref;

export namespace xieite {
	template<typename T>
	concept is_var_vrref_noex = xieite::is_var_vrref<T> && xieite::is_noex<T>;
}
