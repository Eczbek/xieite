export module xieite:set_cv;

import :set_c;
import :set_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_cv = xieite::set_c<qual, xieite::set_v<qual, T>>;
}
