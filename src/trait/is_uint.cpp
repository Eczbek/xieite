export module xieite:is_uint;

import std;

export namespace xieite {
	template<typename T>
	concept is_uint = std::unsigned_integral<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}
