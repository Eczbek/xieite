export module xieite:is_nothrow_copy_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_copy_assign = std::is_nothrow_copy_assignable_v<T>;
}
