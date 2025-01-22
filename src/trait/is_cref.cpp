export module xieite:is_cref;

import :is_clref;
import :is_crref;

export namespace xieite {
	template<typename T>
	concept is_cref = xieite::is_clref<T> || xieite::is_crref<T>;
}
