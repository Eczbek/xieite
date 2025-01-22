export module xieite:is_var_vlref_noex;

import :is_noex;
import :is_var_vlref;

export namespace xieite {
	template<typename T>
	concept is_var_vlref_noex = xieite::is_var_vlref<T> && xieite::is_noex<T>;
}
