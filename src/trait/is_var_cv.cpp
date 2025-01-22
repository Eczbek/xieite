export module xieite:is_var_cv;

import :is_v_referent;
import :is_var_c;

export namespace xieite {
	template<typename T>
	concept is_var_cv = xieite::is_var_c<T> && xieite::is_v_referent<T>;
}
