export module xieite:set_vrref;

import :set_rref;
import :set_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_vrref = xieite::set_v<qual, xieite::set_rref<qual, T>>;
}
