export module xieite:add_vlref_noex;

import :add_noex;
import :add_vlref_referent;

export namespace xieite {
	template<typename T>
	using add_vlref_noex = xieite::add_vlref_referent<xieite::add_noex<T>>;
}
