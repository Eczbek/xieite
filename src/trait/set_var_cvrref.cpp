export module xieite:set_var_cvrref;

import :set_rref_referent;
import :set_var_cv;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cvrref = xieite::set_var_cv<qual, xieite::set_rref_referent<qual, T>>;
}
