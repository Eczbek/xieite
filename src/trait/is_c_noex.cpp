export module xieite:is_c_noex;

import :is_c_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_c_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_c_referent<T>) && xieite::is_noex<T>;
}
