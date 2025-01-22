export module xieite:set_var_noex;

import :set_noex;
import :set_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_noex = xieite::set_var<qual, xieite::set_noex<qual, T>>;
}
