export module xieite:cp_vlref_noex;

import :cp_noex;
import :cp_vlref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vlref_noex = xieite::cp_vlref_referent<T, xieite::cp_noex<T, U>>;
}
