export module xieite:add_cvref_noex;

import :add_cvref_referent;
import :add_noex;

export namespace xieite {
	template<typename T, typename U>
	using add_cvref_noex = xieite::add_cvref_referent<T, xieite::add_noex<U>>;
}
