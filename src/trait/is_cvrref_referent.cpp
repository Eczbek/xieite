export module xieite:is_cvrref_referent;

import :is_cv_referent;
import :is_rref_referent;

export namespace xieite {
	template<typename T>
	concept is_cvrref_referent = xieite::is_cv_referent<T> && xieite::is_rref_referent<T>;
}
