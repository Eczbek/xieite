export module xieite:add_var_cv;

import :add_cv_referent;
import :add_var;

export namespace xieite {
	template<typename T>
	using add_var_cv = xieite::add_var<xieite::add_cv_referent<T>>;
}
