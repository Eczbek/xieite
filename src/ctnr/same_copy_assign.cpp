export module xieite:same_copy_assign;

import std;
import :maybe_copy_assign;

export namespace xieite {
	template<typename T>
	using same_copy_assign = xieite::maybe_copy_assign<std::is_copy_assignable_v<T>>;
}
