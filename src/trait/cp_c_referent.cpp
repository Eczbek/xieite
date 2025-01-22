export module xieite:cp_c_referent;

import :is_c_referent;
import :set_c_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_c_referent = xieite::set_c_referent<xieite::is_c_referent<T>, U>;
}
