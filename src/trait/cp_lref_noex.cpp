export module xieite:cp_lref_noex;

import :is_lref_noex;
import :set_lref_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_lref_noex = xieite::set_lref_noex<xieite::is_lref_noex<T>, U>;
}
