export module xieite:id;

import std;

export namespace xieite {
	template<typename T>
	using id = std::type_identity_t<T>;
}
