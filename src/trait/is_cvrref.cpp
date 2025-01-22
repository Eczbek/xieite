export module xieite:is_cvrref;

import :is_cv;
import :is_rref;

export namespace xieite {
	template<typename T>
	concept is_cvrref = xieite::is_cv<T> && xieite::is_rref<T>;
}
