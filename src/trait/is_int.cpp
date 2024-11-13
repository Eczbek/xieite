export module xieite:is_int;

import std;

export namespace xieite {
	template<typename T>
	concept is_int = std::integral<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}
