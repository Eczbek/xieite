export module xieite:add_clref;

import :add_c;
import :add_lref;

export namespace xieite {
	template<typename T>
	using add_clref = xieite::add_c<xieite::add_lref<T>>;
}
