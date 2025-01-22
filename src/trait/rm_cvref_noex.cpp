export module xieite:rm_cvref_noex;

import :rm_cvref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_cvref_noex = xieite::rm_cvref_referent<xieite::rm_noex<T>>;
}
