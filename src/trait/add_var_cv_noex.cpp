export module xieite:add_var_cv_noex;

import :add_noex;
import :add_var_cv;

export namespace xieite {
	template<typename T>
	using add_var_cv_noex = xieite::add_var_cv<xieite::add_noex<T>>;
}
