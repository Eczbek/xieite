export module xieite:is_fn;

import std;

export namespace xieite {
	template<typename T>
	concept is_fn = std::is_function_v<T>;
}
