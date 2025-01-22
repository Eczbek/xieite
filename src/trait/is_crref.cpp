export module xieite:is_crref;

import :is_c;
import :is_rref;

export namespace xieite {
	template<typename T>
	concept is_crref = xieite::is_c<T> && xieite::is_rref<T>;
}
