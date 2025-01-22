export module xieite:cp_cvrref_noex;

import :cp_cvrref_referent;
import :cp_noex;

export namespace xieite {
	template<typename T, typename U>
	using cp_cvrref_noex = xieite::set_cvrref_referent<T, xieite::cp_noex<T, U>>;
}
