export module xieite:cp_cp_assign;

import std;
import :set_cp_assign;

export namespace xieite {
	template<typename T>
	using cp_cp_assign = xieite::set_cp_assign<std::is_copy_assignable_v<T>>;
}
