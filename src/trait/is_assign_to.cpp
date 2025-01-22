export module xieite:is_assign_to;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_assign_to = std::assignable_from<U, T>;
}
