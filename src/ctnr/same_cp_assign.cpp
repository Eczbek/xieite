export module xieite:same_cp_assign;

import std;
import :set_cp_assign;

export namespace xieite {
	template<typename T>
	using same_cp_assign = xieite::set_cp_assign<std::is_copy_assignable_v<T>>;
}
