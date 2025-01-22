export module xieite:cp_var;

import :is_var;
import :set_var;

export namespace xieite {
	template<typename T, typename U>
	using cp_var = xieite::set_var<xieite::is_var<T>, U>;
}
