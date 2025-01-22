export module xieite:t;

import std;

export namespace xieite {
	template<typename T>
	using t = std::type_identity<T>;
}
