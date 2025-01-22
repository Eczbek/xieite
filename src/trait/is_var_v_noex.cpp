export module xieite:is_var_v_noex;

import :is_noex;
import :is_var_v;

export namespace xieite {
	template<typename T>
	concept is_var_v_noex = xieite::is_var_v<T> && xieite::is_noex<T>;
}
