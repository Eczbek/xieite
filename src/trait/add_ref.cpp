export module xieite:add_ref;

import :cp_lref;
import :cp_rref;

export namespace xieite {
	template<typename T, typename U>
	using add_ref = xieite::cp_lref<T, xieite::cp_rref<T, U>>;
}
