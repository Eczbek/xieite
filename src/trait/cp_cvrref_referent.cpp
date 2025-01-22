export module xieite:cp_cvrref_referent;

import :cp_cv_referent;
import :cp_rref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvrref_referent = xieite::cp_cv_referent<T, xieite::cp_rref_referent<T, U>>;
}
