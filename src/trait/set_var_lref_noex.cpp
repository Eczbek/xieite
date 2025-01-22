export module xieite:set_var_lref_noex;

import :set_noex;
import :set_var_lref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_lref_noex = xieite::set_var_lref<qual, xieite::set_noex<qual, T>>;
}
