export module xieite:is_var_crref;

import :is_rref_referent;
import :is_var_c;

export namespace xieite {
	template<typename T>
	concept is_var_crref = xieite::is_var_c<T> && xieite::is_rref_referent<T>;
}
