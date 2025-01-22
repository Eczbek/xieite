export module xieite:cp_rref_noex;

import :is_rref_noex;
import :set_rref_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_rref_noex = xieite::set_rref_noex<xieite::is_rref_noex<T>, U>;
}
