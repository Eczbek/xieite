export module xieite:rm_clref_noex;

import :rm_clref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_clref_noex = xieite::rm_clref_referent<xieite::rm_noex<T>>;
}
