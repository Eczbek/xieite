export module xieite:add_vlref_referent;

import :add_lref_referent;
import :add_v_referent;

export namespace xieite {
	template<typename T>
	using add_vlref_referent = xieite::add_v_referent<xieite::add_lref_referent<T>>;
}
