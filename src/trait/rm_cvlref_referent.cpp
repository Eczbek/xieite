export module xieite:rm_cvlref_referent;

import :rm_cv_referent;
import :rm_lref_referent;

export namespace xieite {
	template<typename T>
	using rm_cvlref_referent = xieite::rm_cv_referent<xieite::rm_lref_referent<T>>;
}
