export module xieite:cp_cv_noex;

import :cp_cv_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_cv_noex = xieite::set_cv_referent<T, xieite::cp_noex<T, U>>;
}
