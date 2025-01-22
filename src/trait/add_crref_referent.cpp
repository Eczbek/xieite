export module xieite:add_crref_referent;

import :add_c_referent;
import :add_rref_referent;

export namespace xieite {
	template<typename T>
	using add_crref_referent = xieite::add_c_referent<xieite::add_rref_referent<T>>;
}
