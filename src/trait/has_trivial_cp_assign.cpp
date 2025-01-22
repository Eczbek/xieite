export module xieite:has_trivial_cp_assign;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_cp_assign = std::is_trivially_copy_assignable_v<T>;
}
