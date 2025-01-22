export module xieite:cp_cref;

import :cp_c;
import :cp_ref;

export namespace xieite {
	template<typename T, typename U>
	using cp_cref = xieite::cp_c<T, xieite::cp_ref<T, U>>;
}
