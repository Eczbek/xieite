export module xieite:cp_lref;

import :is_lref;
import :set_lref;

export namespace xieite {
	template<typename T, typename U>
	using cp_lref = xieite::set_lref<xieite::is_lref<T>, U>;
}
