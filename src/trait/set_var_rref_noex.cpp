export module xieite:set_var_rref_noex;

import :set_noex;
import :set_var_rref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_rref_noex = xieite::set_var_rref<qual, xieite::set_noex<qual, T>>;
}
