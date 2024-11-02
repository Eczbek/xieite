export module xieite:is_nothrow_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_ctor = std::is_nothrow_constructible_v<T>;
}
