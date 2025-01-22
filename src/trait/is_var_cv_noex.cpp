export module xieite:is_var_cv_noex;

import :is_noex;
import :is_var_cv;

export namespace xieite {
	template<typename T>
	concept is_var_cv_noex = xieite::is_var_cv<T> && xieite::is_noex<T>;
}
