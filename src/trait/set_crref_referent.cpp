export module xieite:set_crref_referent;

import :set_c_referent;
import :set_rref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_crref_referent = xieite::set_c_referent<qual, xieite::set_rref_referent<qual, T>>;
}
