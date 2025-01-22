export module xieite:set_vlref;

import :set_lref;
import :set_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_vlref = xieite::set_v<qual, xieite::set_lref<qual, T>>;
}
