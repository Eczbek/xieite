export module xieite:is_clref_referent;

import :is_c_referent;
import :is_lref_referent;

export namespace xieite {
	template<typename T>
	concept is_clref_referent = xieite::is_c_referent<T> && xieite::is_lref_referent<T>;
}
