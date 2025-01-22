export module xieite:set_var_v;

import :set_v_referent;
import :set_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_v = xieite::set_var<qual, xieite::set_v_referent<qual, T>>;
}
