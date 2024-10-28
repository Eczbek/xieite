export module xieite:is_trivial;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial = std::is_trivial_v<T>;
}
