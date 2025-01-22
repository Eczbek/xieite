export module xieite:set_cvrref_referent;

import :set_cv_referent;
import :set_rref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvrref_referent = xieite::set_cv_referent<qual, xieite::set_rref_referent<qual, T>>;
}
