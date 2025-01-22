export module xieite:is_cvlref;

import :is_cv;
import :is_lref;

export namespace xieite {
	template<typename T>
	concept is_cvlref = xieite::is_cv<T> && xieite::is_lref<T>;
}
