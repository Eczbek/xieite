export module xieite:is_fundamental;

import std;

export namespace xieite {
	template<typename T>
	concept is_fundamental = std::is_fundamental_v<T>;
}
