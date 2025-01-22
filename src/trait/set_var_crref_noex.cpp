export module xieite:set_var_crref_noex;

import :set_noex;
import :set_var_crref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_crref_noex = xieite::set_var_crref<qual, xieite::set_noex<qual, T>>;
}
