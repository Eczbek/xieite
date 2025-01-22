export module xieite:is_var_vrref;

import :is_rref_referent;
import :is_var_v;

export namespace xieite {
	template<typename T>
	concept is_var_vrref = xieite::is_var_v<T> && xieite::is_rref_referent<T>;
}
