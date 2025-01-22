export module xieite:set_var_c_noex;

import :set_noex;
import :set_var_c;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_c_noex = xieite::set_var_c<qual, xieite::set_noex<qual, T>>;
}
