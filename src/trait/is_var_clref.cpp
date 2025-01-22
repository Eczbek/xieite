export module xieite:is_var_clref;

import :is_lref_referent;
import :is_var_c;

export namespace xieite {
	template<typename T>
	concept is_var_clref = xieite::is_var_c<T> && xieite::is_lref_referent<T>;
}
