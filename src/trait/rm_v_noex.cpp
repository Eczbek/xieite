export module xieite:rm_v_noex;

import :rm_noex;
import :rm_v_referent;

export namespace xieite {
	template<typename T>
	using rm_v_noex = xieite::rm_v_referent<xieite::rm_noex<T>>;
}
