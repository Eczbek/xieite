export module xieite:is_assign;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_assign = std::is_assignable_v<T, U>;
}
