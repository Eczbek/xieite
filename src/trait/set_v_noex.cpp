export module xieite:set_v_noex;

import :set_noex;
import :set_v_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_v_noex = xieite::set_v_referent<qual, xieite::set_noex<qual, T>>;
}
