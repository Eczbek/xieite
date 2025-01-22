export module xieite:set_clref;

import :set_c;
import :set_lref;

export namespace xieite {
	template<bool qual, typename T>
	using set_clref = xieite::set_c<qual, xieite::set_lref<qual, T>>;
}
