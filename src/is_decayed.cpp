export module xieite:is_decayed;

import std;

export namespace xieite {
	template<typename T>
	concept is_decayed = std::same_as<T, std::decay_t<T>>;
}
