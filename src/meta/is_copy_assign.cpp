export module xieite:is_copy_assignable;

import std;

export namespace xieite {
	template<typename T>
	concept is_copy_assignable = std::is_copy_assignable_v<T>;
}
