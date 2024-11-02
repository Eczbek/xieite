export module xieite:is_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_assign = std::is_assignable_v<T>;
}
