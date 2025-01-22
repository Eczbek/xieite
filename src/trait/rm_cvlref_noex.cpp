export module xieite:rm_cvlref_noex;

import :rm_cvlref_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_cvlref_noex = xieite::rm_cvlref_referent<xieite::rm_noex<T>>;
}
