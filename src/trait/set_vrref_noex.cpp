export module xieite:set_vrref_noex;

import :set_noex;
import :set_vrref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_vrref_noex = xieite::set_vrref_referent<qual, xieite::set_noex<qual, T>>;
}
