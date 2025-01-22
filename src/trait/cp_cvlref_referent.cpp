export module xieite:cp_cvlref_referent;

import :cp_cv_referent;
import :cp_lref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvlref_referent = xieite::cp_cv_referent<T, xieite::cp_lref_referent<T, U>>;
}
