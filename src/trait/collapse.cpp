export module xieite:collapse;

import :add_rref;
import :cp_cvlref;

export namespace xieite {
	template<typename T, typename U>
	using collapse = xieite::cp_cvlref<T, xieite::add_rref<U>>;
}
