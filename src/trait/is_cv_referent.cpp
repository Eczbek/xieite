export module xieite:is_cv_referent;

import :is_c_referent;
import :is_v_referent;

export namespace xieite {
	template<typename T>
	concept is_cv_referent = xieite::is_c_referent<T> && xieite::is_v_referent<T>;
}
