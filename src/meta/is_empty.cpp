export module xieite:is_empty;

import std;

export namespace xieite {
	template<typename T>
	concept is_empty = std::is_empty_v<T>;
}
