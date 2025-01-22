export module xieite:is_var_c_noex;

import :is_noex;
import :is_var_c;

export namespace xieite {
	template<typename T>
	concept is_var_c_noex = xieite::is_var_c<T> && xieite::is_noex<T>;
}
