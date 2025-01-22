export module xieite:cp_noex;

import :is_noex;
import :set_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_noex = xieite::set_noex<xieite::is_noex<T>, U>;
}
