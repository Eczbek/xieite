export module xieite:is_nothrow_default_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_default_ctor = std::is_nothrow_default_constructible_v<T>;
}
