export module xieite:add_lref_noex;

import :add_lref_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_lref_noex = xieite::add_lref_referent<xieite::add_noex<T>>;
}
