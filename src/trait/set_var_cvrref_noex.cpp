export module xieite:set_var_cvrref_noex;

import :set_noex;
import :set_var_cvrref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cvrref_noex = xieite::set_var_cvrref<qual, xieite::set_noex<qual, T>>;
}
