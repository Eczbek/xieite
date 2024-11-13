export module xieite:is_scalar;

import std;

export namespace xieite {
	template<typename T>
	concept is_scalar = std::is_scalar_v<T>;
}
