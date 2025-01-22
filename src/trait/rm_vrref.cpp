export module xieite:rm_vrref;

import :rm_rref;
import :rm_v;

export namespace xieite {
	template<typename T>
	using rm_vrref = xieite::rm_v<xieite::rm_rref<T>>;
}
