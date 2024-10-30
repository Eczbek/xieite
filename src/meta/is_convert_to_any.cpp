export module xieite:is_convertible_to_any;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_convertible_to_any = (... || std::convertible_to<T, Us>);
}
