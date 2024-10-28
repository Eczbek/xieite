export module xieite:is_arith;

import std;

export namespace xieite {
	template<typename T>
	concept is_arith = std::integral<T> || std::floating_point<T>;
}
