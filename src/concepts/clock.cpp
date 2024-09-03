export module xieite:concepts.Clock;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Clock = std::chrono::is_clock_v<Type>;
}
