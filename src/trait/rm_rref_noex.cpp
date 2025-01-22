export module xieite:rm_rref_noex;

import :rm_noex;
import :rm_rref_referent;

export namespace xieite {
	template<typename T>
	using rm_rref_noex = xieite::rm_rref_referent<xieite::rm_noex<T>>;
}
