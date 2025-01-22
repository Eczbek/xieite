export module xieite:rm_cv_noex;

import :rm_cv_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_cv_noex = xieite::rm_cv_referent<xieite::rm_noex<T>>;
}
