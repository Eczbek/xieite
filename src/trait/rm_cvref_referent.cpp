export module xieite:rm_cvref_referent;

import :rm_cv_referent;
import :rm_ref_referent;

export namespace xieite {
	template<typename T>
	using rm_cvref_referent = xieite::rm_cv_referent<xieite::rm_ref_referent<T>>;
}
