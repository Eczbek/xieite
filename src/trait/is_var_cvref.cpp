export module xieite:is_var_cvref;

import :is_ref_referent;
import :is_var_cv;

export namespace xieite {
	template<typename T>
	concept is_var_cvref = xieite::is_var_cv<T> && xieite::is_ref_referent<T>;
}
