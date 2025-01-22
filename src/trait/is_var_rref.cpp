export module xieite:is_var_rref;

import :is_rref_referent;
import :is_var;

export namespace xieite {
	template<typename T>
	concept is_var_rref = xieite::is_var<T> && xieite::is_rref_referent<T>;
}
