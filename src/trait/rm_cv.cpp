export module xieite:rm_cv;

import :rm_c;
import :rm_v;

export namespace xieite {
	template<typename T>
	using rm_cv = xieite::rm_c<xieite::rm_v<T>>;
}
