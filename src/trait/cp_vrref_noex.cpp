export module xieite:cp_vrref_noex;

import :cp_noex;
import :cp_vrref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_vrref_noex = xieite::cp_vrref_referent<T, xieite::cp_noex<T, U>>;
}
