export module xieite:is_cp_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_cp_assign = std::is_copy_assignable_v<T>;
}
