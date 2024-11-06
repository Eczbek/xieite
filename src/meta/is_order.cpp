export module xieite:is_order;

import std;
import :is_same_as_any;

export namespace xieite {
	template<typename T>
	concept is_order = xieite::is_same_as_any<std::remove_cv_t<T>, std::strong_ordering, std::weak_ordering, std::partial_ordering>;
}
