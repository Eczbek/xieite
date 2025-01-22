export module xieite:cp_c;

import :is_c;
import :set_c;

export namespace xieite {
	template<typename T, typename U>
	using cp_c = xieite::set_c<xieite::is_c<T>, U>;
}
