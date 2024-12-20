export module xieite:same_cp_ctor;

import std;
import :set_cp_ctor;

export namespace xieite {
	template<typename T>
	using same_cp_ctor = xieite::set_cp_ctor<std::is_copy_constructible_v<T>>;
}
