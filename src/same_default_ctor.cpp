export module xieite:same_default_constructible;

import std;
import :maybe_default_constructible;

export namespace xieite {
	template<typename T>
	using same_default_constructible = xieite::maybe_default_constructible<std::is_default_constructible_v<T>>;
}
