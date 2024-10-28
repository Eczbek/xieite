export module xieite:ssize_if_float;

import std;
import :ssize;

export namespace xieite {
	template<typename T>
	using ssize_if_float = std::conditional_t<std::floating_point<T>, xieite::ssize, T>;
}
