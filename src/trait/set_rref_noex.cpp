export module xieite:set_rref_noex;

import :set_noex;
import :set_rref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_rref_noex = xieite::set_rref_referent<qual, xieite::set_noex<qual, T>>;
}
