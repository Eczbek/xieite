export module xieite:cp_cvlref_noex;

import :cp_cvlref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvlref_noex = xieite::set_cvlref_referent<T, xieite::cp_noex<T, U>>;
}
