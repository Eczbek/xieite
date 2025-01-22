export module xieite:cp_cvref_noex;

import :cp_cvref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvref_noex = xieite::set_cvref_referent<T, xieite::cp_noex<T, U>>;
}
