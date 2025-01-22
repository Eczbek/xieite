export module xieite:set_vlref_noex;

import :set_noex;
import :set_vlref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_vlref_noex = xieite::set_vlref_referent<qual, xieite::set_noex<qual, T>>;
}
