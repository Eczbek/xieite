export module xieite:is_crref_noex;

import :is_crref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_crref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_crref_referent<T>) && xieite::is_noex<T>;
}
