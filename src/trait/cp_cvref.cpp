export module xieite:cp_cvref;

import :cp_cv;
import :cp_ref;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvref = xieite::cp_cv<T, xieite::cp_ref<T, U>>;
}
