export module xieite:set_var_cv_noex;

import :set_noex;
import :set_var_cv;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cv_noex = xieite::set_var_cv<qual, xieite::set_noex<qual, T>>;
}
