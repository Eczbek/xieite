export module xieite:cp_cp_ctor;

import std;
import :set_cp_ctor;

export namespace xieite {
	template<typename T>
	using cp_cp_ctor = xieite::set_cp_ctor<std::is_copy_constructible_v<T>>;
}
