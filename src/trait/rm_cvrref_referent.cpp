export module xieite:rm_cvrref_referent;

import :rm_cv_referent;
import :rm_rref_referent;

export namespace xieite {
	template<typename T>
	using rm_cvrref_referent = xieite::rm_cv_referent<xieite::rm_rref_referent<T>>;
}
