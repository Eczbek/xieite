export module xieite:is_cvlref_noex;

import :is_cvlref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_cvlref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cvlref_referent<T>) && xieite::is_noex<T>;
}
