export module xieite:is_nothrow_copy_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_copy_ctor = std::is_nothrow_copy_constructible_v<T>;
}
