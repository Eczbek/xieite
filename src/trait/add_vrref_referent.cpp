export module xieite:add_vrref_referent;

import :add_rref_referent;
import :add_v_referent;

export namespace xieite {
	template<typename T>
	using add_vrref_referent = xieite::add_v_referent<xieite::add_rref_referent<T>>;
}
