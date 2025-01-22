export module xieite:add_cvrref;

import :add_cv;
import :add_rref;

export namespace xieite {
	template<typename T>
	using add_cvrref = xieite::add_cv<xieite::add_rref<T>>;
}
