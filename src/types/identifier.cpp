export module xieite:types.identifier;

import std;
import :functors.Counter;

using TypeIdentifierCounter = xieite::functors::Counter<>;

export namespace xieite::types {
	template<typename>
	constexpr std::size_t identifier = TypeIdentifierCounter::advance();
}
