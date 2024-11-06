export module xieite:same_copy_ctor;

import std;
import :maybe_copy_ctor;

export namespace xieite {
	template<typename T>
	using same_copy_ctor = xieite::maybe_copy_ctor<std::is_copy_constructible_v<T>>;
}
