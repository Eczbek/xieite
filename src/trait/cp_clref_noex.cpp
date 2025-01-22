export module xieite:cp_clref_noex;

import :cp_clref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_clref_noex = xieite::cp_clref_referent<T, xieite::cp_noex<T, U>>;
}
