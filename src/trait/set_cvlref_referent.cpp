export module xieite:set_cvlref_referent;

import :set_cv_referent;
import :set_lref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvlref_referent = xieite::set_cv_referent<qual, xieite::set_lref_referent<qual, T>>;
}
