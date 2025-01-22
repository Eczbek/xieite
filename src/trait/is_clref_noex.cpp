export module xieite:is_clref_noex;

import :is_clref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_clref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_clref_referent<T>) && xieite::is_noex<T>;
}
