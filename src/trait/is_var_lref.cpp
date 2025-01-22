export module xieite:is_var_lref;

import :is_lref_referent;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_lref = xieite::is_var<T> && xieite::is_lref_referent<T>;
}
