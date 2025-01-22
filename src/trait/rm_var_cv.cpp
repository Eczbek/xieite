export module xieite:rm_var_cv;

import :rm_cv_referent;
import :rm_var;

export namespace xieite {
	template<typename T>
	using rm_var_cv = xieite::rm_var<xieite::rm_cv_referent<T>>;
}
