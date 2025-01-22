export module xieite:set_cvlref_noex;

import :set_cvlref_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvlref_noex = xieite::set_cvlref_referent<qual, xieite::set_noex<qual, T>>;
}
