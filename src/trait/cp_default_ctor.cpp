export module xieite:cp_default_ctor;

import std;
import :set_default_ctor;

export namespace xieite {
	template<typename T>
	using cp_default_ctor = xieite::set_default_ctor<std::is_default_constructible_v<T>>;
}
