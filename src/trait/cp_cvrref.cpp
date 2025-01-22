export module xieite:cp_cvrref;

import :cp_cv;
import :cp_rref;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvrref = xieite::cp_cv<T, xieite::cp_rref<T, U>>;
}
