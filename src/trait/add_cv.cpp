export module xieite:add_cv;

import :add_c;
import :add_v;

export namespace xieite {
	template<typename T>
	using add_cv = xieite::add_c<xieite::add_v<T>>;
}
