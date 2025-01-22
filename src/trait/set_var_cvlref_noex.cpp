export module xieite:set_var_cvlref_noex;

import :set_noex;
import :set_var_cvlref;

export namespace xieite {
	template<bool qual, typename T>
	using set_var_cvlref_noex = xieite::set_var_cvlref<qual, xieite::set_noex<qual, T>>;
}
