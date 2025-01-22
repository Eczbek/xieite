export module xieite:cp_cvlref;

import :cp_cv;
import :cp_lref;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvlref = xieite::cp_cv<T, xieite::cp_lref<T, U>>;
}
