export module xieite:rm_var_cv_noex;

import :rm_noex;
import :rm_var_cv;

export namespace xieite {
	template<typename T>
	using rm_var_cv_noex = xieite::rm_var_cv<xieite::rm_noex<T>>;
}
