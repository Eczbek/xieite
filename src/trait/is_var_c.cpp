export module xieite:is_var_c;

import :is_c_referent;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_c = xieite::is_var<T> && xieite::is_c_referent<T>;
}
