export module xieite:cp_cref_noex;

import :cp_cref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_cref_noex = xieite::cp_cref_referent<T, xieite::cp_noex<T, U>>;
}
