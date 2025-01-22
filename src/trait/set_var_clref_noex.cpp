export module xieite:set_var_clref_noex;

import :set_noex;
import :set_var_clref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_clref_noex = xieite::set_var_clref<qual, xieite::set_noex<qual, T>>;
}
