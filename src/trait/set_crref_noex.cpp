export module xieite:set_crref_noex;

import :set_crref_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_crref_noex = xieite::set_crref_referent<qual, xieite::set_noex<qual, T>>;
}
