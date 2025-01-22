export module xieite:set_clref_noex;

import :set_clref_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_clref_noex = xieite::set_clref_referent<qual, xieite::set_noex<qual, T>>;
}
