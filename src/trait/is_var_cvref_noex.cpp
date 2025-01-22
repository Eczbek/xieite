export module xieite:is_var_cvref_noex;

import :is_noex;
import :is_var_cvref;

export namespace xieite {
	template<typename T>
	concept is_var_cvref_noex = xieite::is_var_cvref<T> && xieite::is_noex<T>;
}
