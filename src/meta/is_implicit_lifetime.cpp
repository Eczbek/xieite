export module xieite:is_implicit_lifetime;

import std;

export namespace xieite {
	template<typename T>
	concept is_implicit_lifetime = std::is_implicit_lifetime_v<T>;
}
