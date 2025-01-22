export module xieite:is_rref_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_rref_referent;

export namespace xieite {
	template<typename T>
	concept is_rref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_rref_referent<T>) && xieite::is_noex<T>;
}
