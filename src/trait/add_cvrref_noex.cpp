export module xieite:add_cvrref_noex;

import :add_cvrref_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_cvrref_noex = xieite::add_cvrref_referent<xieite::add_noex<T>>;
}
