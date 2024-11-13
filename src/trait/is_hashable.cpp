export module xieite:is_hashable;

import std;
import :is_invoc;

export namespace xieite {
	template<typename T, typename Hasher = std::hash<T>>
	concept is_hashable = xieite::is_invoc<Hasher, std::size_t(T)>;
}
