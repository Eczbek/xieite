export module xieite:add_vref;

import :add_ref;
import :add_v;

export namespace xieite {
	template<typename T, typename U>
	using add_vref = xieite::add_v<xieite::add_ref<T, U>>;
}
