export module xieite:cp_crref_noex;

import :cp_crref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_crref_noex = xieite::cp_crref_referent<T, xieite::cp_noex<T, U>>;
}
