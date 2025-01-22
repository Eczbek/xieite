export module xieite:is_vlref_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_vlref_referent;

export namespace xieite {
	template<typename T>
	concept is_vlref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vlref_referent<T>) && xieite::is_noex<T>;
}
