export module xieite:same_copy_assignable;

import std;
import :maybe_copy_assignable;

export namespace xieite {
	template<typename T>
	using same_copy_assignable = xieite::maybe_copy_assignable<std::is_copy_assignable_v<T>>;
}
