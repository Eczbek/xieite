export module xieite:cp_var_cv_noex;

import :cp_noex;
import :cp_var_cv;

export namespace xieite {
	template<typename T, typename U>
	using cp_var_cv_noex = xieite::cp_var_cv<T, xieite::cp_noex<T, U>>;
}
