export module xieite:is_vrref_referent;

import :is_rref_referent;
import :is_v_referent;

export namespace xieite {
	template<typename T>
	concept is_vrref_referent = xieite::is_v_referent<T> && xieite::is_rref_referent<T>;
}
