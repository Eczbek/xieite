export module xieite:add_cref;

import :add_c;
import :add_ref;

export namespace xieite {
	template<typename T, typename U>
	using add_cref = xieite::add_c<xieite::add_ref<T, U>>;
}
