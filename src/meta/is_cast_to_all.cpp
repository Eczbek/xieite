export module xieite:is_cast_to_all;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_cast_to_all = (... && std::convertible_to<T, Us>);
}
