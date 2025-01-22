export module xieite:is_cv;

import :is_c;
import :is_v;

export namespace xieite {
	template<typename T>
	concept is_cv = xieite::is_c<T> && xieite::is_v<T>;
}
