export module xieite:add_cref_referent;

import :add_c_referent;
import :add_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using add_cref_referent = xieite::add_c_referent<xieite::add_ref_referent<T, U>>;
}
