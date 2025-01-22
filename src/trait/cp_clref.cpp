export module xieite:cp_clref;

import :cp_c;
import :cp_lref;

export namespace xieite {
	template<typename T, typename U>
	using cp_clref = xieite::cp_c<T, xieite::cp_lref<T, U>>;
}
