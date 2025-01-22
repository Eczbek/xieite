export module xieite:set_lref_noex;

import :set_lref_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_lref_noex = xieite::set_lref_referent<qual, xieite::set_noex<qual, T>>;
}
