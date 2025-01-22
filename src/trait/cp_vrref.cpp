export module xieite:cp_vrref;

import :cp_rref;
import :cp_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_vrref = xieite::cp_v<T, xieite::cp_rref<T, U>>;
}
