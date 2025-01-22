export module xieite:is_var_cvrref;

import :is_rref_referent;
import :is_var_cv;

export namespace xieite {
	template<typename T>
	concept is_var_cvrref = xieite::is_var_cv<T> && xieite::is_rref_referent<T>;
}
