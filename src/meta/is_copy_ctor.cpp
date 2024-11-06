export module xieite:is_copy_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_copy_ctor = std::is_copy_constructible_v<T>;
}
