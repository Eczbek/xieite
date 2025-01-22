export module xieite:cp_cv;

import :cp_c;
import :cp_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_cv = xieite::cp_c<T, xieite::cp_v<T, U>>;
}
