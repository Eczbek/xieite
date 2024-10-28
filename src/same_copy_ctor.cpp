export module xieite:same_copy_constructible;

import std;
import :maybe_copy_constructible;

export namespace xieite {
	template<typename T>
	using same_copy_constructible = xieite::maybe_copy_constructible<std::is_copy_constructible_v<T>>;
}
