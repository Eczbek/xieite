export module xieite:same_dflt_ctor;

import std;
import :set_dflt_ctor;

export namespace xieite {
	template<typename T>
	using same_dflt_ctor = xieite::set_dflt_ctor<std::is_default_constructible_v<T>>;
}
