export module xieite:set_vrref_referent;

import :set_rref_referent;
import :set_v_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_vrref_referent = xieite::set_v_referent<qual, xieite::set_rref_referent<qual, T>>;
}
