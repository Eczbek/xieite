export module xieite:same_default_ctor;

import std;
import :maybe_default_ctor;

export namespace xieite {
	template<typename T>
	using same_default_ctor = xieite::maybe_default_ctor<std::is_default_constructible_v<T>>;
}
