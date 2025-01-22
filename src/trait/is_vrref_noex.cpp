export module xieite:is_vrref_noex;

import :is_m_fn_ptr;
import :is_noex;
import :is_vrref_referent;

export namespace xieite {
	template<typename T>
	concept is_vrref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vrref_referent<T>) && xieite::is_noex<T>;
}
