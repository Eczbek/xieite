export module xieite:cp_v_noex;

import :is_v_noex;
import :set_v_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_v_noex = xieite::set_v_noex<xieite::is_v_noex<T>, U>;
}
