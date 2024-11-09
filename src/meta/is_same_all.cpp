export module xieite:is_same_all;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_same_all = (... && std::same_as<T, Us>);
}
