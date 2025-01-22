export module xieite:set_var_vrref;

import :set_rref_referent;
import :set_var_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref = xieite::set_var_v<qual, xieite::set_rref_referent<qual, T>>;
}
