export module xieite:cp_vref_noex;

import :cp_noex;
import :cp_vref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vref_noex = xieite::cp_vref_referent<T, xieite::cp_noex<T, U>>;
}
