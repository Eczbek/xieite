export module xieite:set_var_clref;

import :set_lref_referent;
import :set_var_c;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_clref = xieite::set_var_c<qual, xieite::set_lref_referent<qual, T>>;
}
