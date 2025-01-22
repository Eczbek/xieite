export module xieite:rm_cv_referent;

import :rm_c_referent;
import :rm_v_referent;

export namespace xieite {
	template<typename T>
	using rm_cv_referent = xieite::rm_c_referent<xieite::rm_v_referent<T>>;
}
