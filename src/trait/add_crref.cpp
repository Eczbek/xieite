export module xieite:add_crref;

import :add_c;
import :add_rref;

export namespace xieite {
	template<typename T>
	using add_crref = xieite::add_c<xieite::add_rref<T>>;
}
