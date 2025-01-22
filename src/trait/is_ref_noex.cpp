export module xieite:is_ref_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_ref_referent;

export namespace xieite {
	template<typename T>
	concept is_ref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_ref_referent<T>) && xieite::is_noex<T>;
}
