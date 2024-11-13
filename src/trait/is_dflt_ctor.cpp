export module xieite:is_dflt_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_dflt_ctor = std::is_default_constructible_v<T>;
}
