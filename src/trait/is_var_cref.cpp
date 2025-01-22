export module xieite:is_var_cref;

import :is_ref_referent;
import :is_var_c;

export namespace xieite {
	template<typename T>
	concept is_var_cref = xieite::is_var_c<T> && xieite::is_ref_referent<T>;
}
