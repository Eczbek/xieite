export module xieite:rm_lref_noex;

import :rm_lref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_lref_noex = xieite::rm_lref_referent<xieite::rm_noex<T>>;
}
