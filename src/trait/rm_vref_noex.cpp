export module xieite:rm_vref_noex;

import :rm_noex;
import :rm_vref_referent;

export namespace xieite {
	template<typename T>
	using rm_vref_noex = xieite::rm_vref_referent<xieite::rm_noex<T>>;
}
