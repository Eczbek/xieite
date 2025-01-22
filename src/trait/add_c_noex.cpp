export module xieite:add_c_noex;

import :add_c_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_c_noex = xieite::add_c_referent<xieite::add_noex<T>>;
}
