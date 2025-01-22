export module xieite:cp_crref;

import :cp_c;
import :cp_rref;

export namespace xieite {
	template<typename T, typename U>
	using cp_crref = xieite::cp_c<T, xieite::cp_rref<T, U>>;
}
