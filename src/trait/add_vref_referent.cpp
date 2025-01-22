export module xieite:add_vref_referent;

import :add_ref_referent;
import :add_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using add_vref_referent = xieite::add_v_referent<xieite::add_ref_referent<T, U>>;
}
