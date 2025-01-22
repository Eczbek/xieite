export module xieite:is_v_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_v_referent;

export namespace xieite {
	template<typename T>
	concept is_v_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_v_referent<T>) && xieite::is_noex<T>;
}
