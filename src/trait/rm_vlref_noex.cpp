export module xieite:rm_vlref_noex;

import :rm_noex;
import :rm_vlref_referent;

export namespace xieite {
	template<typename T>
	using rm_vlref_noex = xieite::rm_vlref_referent<xieite::rm_noex<T>>;
}
