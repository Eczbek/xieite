export module xieite:set_var_cv;

import :set_v_referent;
import :set_var_c;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cv = xieite::set_var_c<qual, xieite::set_v_referent<qual, T>>;
}
