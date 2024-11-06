export module xieite:is_cast_to_any;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_cast_to_any = (... || std::convertible_to<T, Us>);
}
