export module xieite:set_crref;

import :set_c;
import :set_rref;

export namespace xieite {
	template<bool qual, typename T>
	using set_crref = xieite::set_c<qual, xieite::set_rref<qual, T>>;
}
