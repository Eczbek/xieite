export module xieite:rm_c_noex;

import :rm_c_referent;
import :rm_noex;

export namespace xieite {
	template<typename T>
	using rm_c_noex = xieite::rm_c_referent<xieite::rm_noex<T>>;
}
