export module xieite:set_var_cvlref;

import :set_lref_referent;
import :set_var_cv;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cvlref = xieite::set_var_cv<qual, xieite::set_lref_referent<qual, T>>;
}
