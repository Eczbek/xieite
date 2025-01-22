export module xieite:add_vlref;

import :add_lref;
import :add_v;

export namespace xieite {
	template<typename T>
	using add_vlref = xieite::add_v<xieite::add_lref<T>>;
}
