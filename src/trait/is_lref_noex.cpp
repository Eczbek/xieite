export module xieite:is_lref_noex;

import :is_lref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_lref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_lref_referent<T>) && xieite::is_noex<T>;
}
