export module xieite:is_var_vref;

import :is_ref_referent;
import :is_var_v;

export namespace xieite {
	template<typename T>
	concept is_var_vref = xieite::is_var_v<T> && xieite::is_ref_referent<T>;
}
