export module xieite:cp_c_noex;

import :is_c_noex;
import :set_c_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_c_noex = xieite::set_c_noex<xieite::is_c_noex<T>, U>;
}
