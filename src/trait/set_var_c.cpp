export module xieite:set_var_c;

import :set_c_referent;
import :set_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_c = xieite::set_var<qual, xieite::set_c_referent<qual, T>>;
}
