export module xieite:is_cvref_noex;

import :is_cvref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_cvref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cvref_referent<T>) && xieite::is_noex<T>;
}
