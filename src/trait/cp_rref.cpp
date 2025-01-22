export module xieite:cp_rref;

import :is_rref;
import :set_rref;

export namespace xieite {
	template<typename T, typename U>
	using cp_rref = xieite::set_rref<xieite::is_rref<T>, U>;
}
