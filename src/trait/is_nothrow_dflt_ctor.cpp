export module xieite:is_nothrow_dflt_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_dflt_ctor = std::is_nothrow_default_constructible_v<T>;
}
