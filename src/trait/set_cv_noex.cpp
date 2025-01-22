export module xieite:set_cv_noex;

import :set_cv_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_cv_noex = xieite::set_cv_referent<qual, xieite::set_noex<qual, T>>;
}
