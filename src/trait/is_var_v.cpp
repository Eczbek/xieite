export module xieite:is_var_v;

import :is_v_referent;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_v = xieite::is_var<T> && xieite::is_v_referent<T>;
}
