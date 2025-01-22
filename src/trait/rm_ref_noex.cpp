export module xieite:rm_ref_noex;

import :rm_noex;
import :rm_ref_referent;

export namespace xieite {
	template<typename T>
	using rm_ref_noex = xieite::rm_ref_referent<xieite::rm_noex<T>>;
}
