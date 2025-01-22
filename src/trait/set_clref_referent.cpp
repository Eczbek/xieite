export module xieite:set_clref_referent;

import :set_c_referent;
import :set_lref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_clref_referent = xieite::set_c_referent<qual, xieite::set_lref_referent<qual, T>>;
}
