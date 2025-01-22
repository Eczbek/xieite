export module xieite:set_cvrref_noex;

import :set_cvrref_referent;
import :set_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvrref_noex = xieite::set_cvrref_referent<qual, xieite::set_noex<qual, T>>;
}
