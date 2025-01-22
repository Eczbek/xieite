export module xieite:is_clref;

import :is_c;
import :is_lref;

export namespace xieite {
	template<typename T>
	concept is_clref = xieite::is_c<T> && xieite::is_lref<T>;
}
