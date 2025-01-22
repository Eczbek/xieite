export module xieite:is_cvlref_referent;

import :is_cv_referent;
import :is_lref_referent;

export namespace xieite {
	template<typename T>
	concept is_cvlref_referent = xieite::is_cv_referent<T> && xieite::is_lref_referent<T>;
}
