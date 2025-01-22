export module xieite:is_var_cvlref;

import :is_lref_referent;
import :is_var_cv;

export namespace xieite {
	template<typename T>
	concept is_var_cvlref = xieite::is_var_cv<T> && xieite::is_lref_referent<T>;
}
