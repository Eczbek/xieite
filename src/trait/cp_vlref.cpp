export module xieite:cp_vlref;

import :cp_lref;
import :cp_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_vlref = xieite::cp_v<T, xieite::cp_lref<T, U>>;
}
