export module xieite:set_var_vlref_noex;

import :set_noex;
import :set_var_vlref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref_noex = xieite::set_var_vlref<qual, xieite::set_noex<qual, T>>;
}
