export module xieite:rm_vlref_referent;

import :rm_lref_referent;
import :rm_v_referent;

export namespace xieite {
	template<typename T>
	using rm_vlref_referent = xieite::rm_v_referent<xieite::rm_lref_referent<T>>;
}
