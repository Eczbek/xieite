export module xieite:is_triv;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv = std::is_trivial_v<T>;
}
