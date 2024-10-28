export module xieite:is_default_constructible;

import std;

export namespace xieite {
	template<typename T>
	concept is_default_constructible = std::is_default_constructible_v<T>;
}
