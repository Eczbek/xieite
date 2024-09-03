export module xieite:traits.IsStream;

import std;
import :concepts.Stream;

export namespace xieite::traits {
	template<typename Type>
	struct IsStream
	: std::bool_constant<xieite::concepts::Stream<Type>> {};
}
