export module xieite:is_polymorphic;

import std;

export namespace xieite {
	template<typename T>
	concept is_polymorphic = std::is_polymorphic_v<T>;
}
