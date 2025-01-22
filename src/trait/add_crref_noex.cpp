export module xieite:add_crref_noex;

import :add_crref_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_crref_noex = xieite::add_crref_referent<xieite::add_noex<T>>;
}
