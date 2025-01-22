export module xieite:rm_cvrref;

import :rm_cv;
import :rm_rref;

export namespace xieite {
	template<typename T>
	using rm_cvrref = xieite::rm_cv<xieite::rm_rref<T>>;
}
