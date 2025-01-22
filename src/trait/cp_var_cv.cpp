export module xieite:cp_var_cv;

import :cp_cv_referent;
import :cp_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cv = xieite::cp_var<T, xieite::cp_cv_referent<T, U>>;
}
