export module xieite:is_ref;

import std;

export namespace xieite {
	template<typename T>
	concept is_ref = std::is_reference_v<T>;
}
