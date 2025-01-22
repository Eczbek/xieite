export module xieite:rm_cvrref_noex;

import :rm_cvrref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_cvrref_noex = xieite::rm_cvrref_referent<xieite::rm_noex<T>>;
}
