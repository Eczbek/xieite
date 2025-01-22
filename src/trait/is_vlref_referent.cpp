export module xieite:is_vlref_referent;

import :is_lref_referent;
import :is_v_referent;

export namespace xieite {
	template<typename T>
	concept is_vlref_referent = xieite::is_v_referent<T> && xieite::is_lref_referent<T>;
}
