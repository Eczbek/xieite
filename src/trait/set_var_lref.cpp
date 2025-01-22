export module xieite:set_var_lref;

import :set_lref_referent;
import :set_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_lref = xieite::set_var<qual, xieite::set_lref_referent<qual, T>>;
}
