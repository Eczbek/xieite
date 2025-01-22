export module xieite:rm_vrref_noex;

import :rm_noex;
import :rm_vrref_referent;

export namespace xieite {
	template<typename T>
	using rm_vrref_noex = xieite::rm_vrref_referent<xieite::rm_noex<T>>;
}
