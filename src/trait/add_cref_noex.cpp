export module xieite:add_cref_noex;

import :add_cref_referent;
import :add_noex;

export namespace xieite {
	template<typename T, typename U>
	using add_cref_noex = xieite::add_cref_referent<T, xieite::add_noex<U>>;
}
