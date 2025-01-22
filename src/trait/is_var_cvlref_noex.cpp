export module xieite:is_var_cvlref_noex;

import :is_noex;
import :is_var_cvlref;

export namespace xieite {
	template<typename T>
	concept is_var_cvlref_noex = xieite::is_var_cvlref<T> && xieite::is_noex<T>;
}
