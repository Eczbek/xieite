export module xieite:add_v_noex;

import :add_noex;
import :add_v_referent;

export namespace xieite {
	template<typename T>
	using add_v_noex = xieite::add_v_referent<xieite::add_noex<T>>;
}
