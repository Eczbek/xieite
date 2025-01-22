export module xieite:set_var_v_noex;

import :set_noex;
import :set_var_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_v_noex = xieite::set_var_v<qual, xieite::set_noex<qual, T>>;
}
