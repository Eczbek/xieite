export module xieite:add_ref_noex;

import :add_noex;
import :add_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using add_ref_noex = xieite::add_ref_referent<T, xieite::add_noex<U>>;
}
