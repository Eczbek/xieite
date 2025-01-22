export module xieite:add_vref_noex;

import :add_noex;
import :add_vref_referent;

export namespace xieite {
	template<typename T, typename U>
	using add_vref_noex = xieite::add_vref_referent<T, xieite::add_noex<U>>;
}
