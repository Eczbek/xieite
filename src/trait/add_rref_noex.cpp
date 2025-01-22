export module xieite:add_rref_noex;

import :add_noex;
import :add_rref_referent;

export namespace xieite {
	template<typename T>
	using add_rref_noex = xieite::add_rref_referent<xieite::add_noex<T>>;
}
