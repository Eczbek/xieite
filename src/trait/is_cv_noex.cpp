export module xieite:is_cv_noex;

import :is_cv_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_cv_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cv_referent<T>) && xieite::is_noex<T>;
}
