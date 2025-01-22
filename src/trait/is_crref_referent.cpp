export module xieite:is_crref_referent;

import :is_c_referent;
import :is_rref_referent;

export namespace xieite {
	template<typename T>
	concept is_crref_referent = xieite::is_c_referent<T> && xieite::is_rref_referent<T>;
}
