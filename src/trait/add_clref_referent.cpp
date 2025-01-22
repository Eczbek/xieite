export module xieite:add_clref_referent;

import :add_c_referent;
import :add_lref_referent;

export namespace xieite {
	template<typename T>
	using add_clref_referent = xieite::add_c_referent<xieite::add_lref_referent<T>>;
}
