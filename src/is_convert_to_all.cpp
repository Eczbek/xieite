export module xieite:is_convertible_to_all;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_convertible_to_all = (... && std::convertible_to<T, Us>);
}
