export module xieite:cp_rref_referent;

import :is_rref_referent;
import :set_rref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_rref_referent = xieite::set_rref_referent<xieite::is_rref_referent<T>, U>;
}
