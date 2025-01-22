export module xieite:set_c_noex;

import :set_c_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_c_noex = xieite::set_c_referent<qual, xieite::set_noex<qual, T>>;
}
