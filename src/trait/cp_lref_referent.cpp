export module xieite:cp_lref_referent;

import :is_lref_referent;
import :set_lref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_lref_referent = xieite::set_lref_referent<xieite::is_lref_referent<T>, U>;
}
