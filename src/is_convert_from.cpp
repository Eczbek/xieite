export module xieite:is_convertible_from;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_convertible_from = std::convertible_to<U, T>;
}
