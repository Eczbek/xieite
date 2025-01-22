export module xieite:set_var_crref;

import :set_rref_referent;
import :set_var_c;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_crref = xieite::set_var_c<qual, xieite::set_rref_referent<qual, T>>;
}
