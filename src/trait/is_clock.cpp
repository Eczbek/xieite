export module xieite:is_clock;

import std;

export namespace xieite {
	template<typename T>
	concept is_clock = std::chrono::is_clock_v<T>;
}
