export module xieite:is_numeric;

import std;
import :is_arith;

export namespace xieite {
	template<typename T>
	concept is_numeric = xieite::is_arith<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}
