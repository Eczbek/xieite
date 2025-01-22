export module xieite:set_var_vrref_noex;

import :set_noex;
import :set_var_vrref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref_noex = xieite::set_var_vrref<qual, xieite::set_noex<qual, T>>;
}
