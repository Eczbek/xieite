export module xieite:is_vref_referent;

import :is_ref_referent;
import :is_v_referent;

export namespace xieite {
	template<typename T>
	concept is_vref_referent = xieite::is_v_referent<T> && xieite::is_ref_referent<T>;
}
