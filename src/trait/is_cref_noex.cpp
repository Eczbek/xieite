export module xieite:is_cref_noex;

import :is_cref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_cref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cref_referent<T>) && xieite::is_noex<T>;
}
