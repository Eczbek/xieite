export module xieite:is_copy_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_copy_assign = std::is_copy_assignable_v<T>;
}
