export module xieite:cp_cvref_referent;

import :cp_cv_referent;
import :cp_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvref_referent = xieite::cp_cv_referent<T, xieite::cp_ref_referent<T, U>>;
}
