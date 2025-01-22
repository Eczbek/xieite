export module xieite:set_cvlref;

import :set_cv;
import :set_lref;

export namespace xieite {
	template<bool qual, typename T>
	using set_cvlref = xieite::set_cv<qual, xieite::set_lref<qual, T>>;
}
