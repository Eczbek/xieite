export module xieite:is_triv_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_ctor = std::is_trivially_constructible_v<T>;
}
