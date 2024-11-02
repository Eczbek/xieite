export module xieite:is_nothrow_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_assign = std::is_nothrow_assignable_v<T>;
}
