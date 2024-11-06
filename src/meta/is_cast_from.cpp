export module xieite:is_cast_from;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_cast_from = std::convertible_to<U, T>;
}
