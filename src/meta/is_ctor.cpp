export module xieite:is_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_ctor = std::is_constructible_v<T>;
}
