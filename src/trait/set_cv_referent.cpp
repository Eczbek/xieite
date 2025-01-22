export module xieite:set_cv_referent;

import :set_c_referent;
import :set_v_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_cv = xieite::set_c_referent<qual, xieite::set_v_referent<qual, T>>;
}
