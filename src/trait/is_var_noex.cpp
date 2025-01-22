export module xieite:is_var_noex;

import :is_noex;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_noex = xieite::is_var<T> && xieite::is_noex<T>;
}
