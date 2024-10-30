export module xieite:is_copy_constructible;

import std;

export namespace xieite {
	template<typename T>
	concept is_copy_constructible = std::is_copy_constructible_v<T>;
}
