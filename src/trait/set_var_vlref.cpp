export module xieite:set_var_vlref;

import :set_lref_referent;
import :set_var_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref = xieite::set_var_v<qual, xieite::set_lref_referent<qual, T>>;
}
