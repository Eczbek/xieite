export module xieite:set_cvrref;

import :set_cv;
import :set_rref;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvrref = xieite::set_cv<qual, xieite::set_rref<qual, T>>;
}
