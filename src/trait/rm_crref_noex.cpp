export module xieite:rm_crref_noex;

import :rm_crref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_crref_noex = xieite::rm_crref_referent<xieite::rm_noex<T>>;
}
