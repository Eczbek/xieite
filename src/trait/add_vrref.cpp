export module xieite:add_vrref;

import :add_rref;
import :add_v;

export namespace xieite {
	template<typename T>
	using add_vrref = xieite::add_v<xieite::add_rref<T>>;
}
