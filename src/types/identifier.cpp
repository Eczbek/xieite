export module xieite:types.identifier;

import std;
import :functors.counter;

constexpr auto identifierCounterTag = [] {};

export namespace xieite::types {
	template<typename>
	constexpr std::size_t identifier = xieite::functors::counter<identifierCounterTag>();
}
