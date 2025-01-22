export module xieite:set_var_rref;

import :set_rref_referent;
import :set_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_rref = xieite::set_var<qual, xieite::set_rref_referent<qual, T>>;
}
