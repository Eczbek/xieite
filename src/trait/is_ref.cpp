export module xieite:is_ref;

import :is_lref;
import :is_rref;

export namespace xieite {
	template<typename T>
	concept is_ref = xieite::is_lref<T> || xieite::is_rref<T>;
}
