export module xieite:is_vref_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_vref_referent;

export namespace xieite {
	template<typename T>
	concept is_vref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vref_referent<T>) && xieite::is_noex<T>;
}
