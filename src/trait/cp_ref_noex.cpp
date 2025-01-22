export module xieite:cp_ref_noex;

import :cp_noex;
import :cp_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_ref_noex = xieite::cp_ref_referent<T, xieite::cp_noex<T, U>>;
}
