export module xieite:rm_cvlref;

import :rm_cv;
import :rm_lref;

export namespace xieite {
	template<typename T>
	using rm_cvlref = xieite::rm_cv<xieite::rm_lref<T>>;
}
