export module xieite:is_var_ref;

import :is_ref_referent;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_ref = xieite::is_var<T> && xieite::is_ref_referent<T>;
}
