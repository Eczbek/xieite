export module xieite:is_cvrref_noex;

import :is_cvrref_referent;
import :is_m_fn_ptr;
import :is_noex;

export namespace xieite {
	template<typename T>
	concept is_cvrref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cvrref_referent<T>) && xieite::is_noex<T>;
}
