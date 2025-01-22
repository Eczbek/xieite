export module xieite:has_cp_assign;

import std;

export namespace xieite {
	template<typename T>
	concept has_cp_assign = std::is_copy_assignable_v<T>;
}
