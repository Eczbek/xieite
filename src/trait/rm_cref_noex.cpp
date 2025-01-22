export module xieite:rm_cref_noex;

import :rm_cref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_cref_noex = xieite::rm_cref_referent<xieite::rm_noex<T>>;
}
