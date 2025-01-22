export module xieite:set_vlref_referent;

import :set_lref_referent;
import :set_v_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_vlref_referent = xieite::set_v_referent<qual, xieite::set_lref_referent<qual, T>>;
}
