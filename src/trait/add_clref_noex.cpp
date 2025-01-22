export module xieite:add_clref_noex;

import :add_clref_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_clref_noex = xieite::add_clref_referent<xieite::add_noex<T>>;
}
