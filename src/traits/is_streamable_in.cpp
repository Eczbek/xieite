export module xieite:traits.IsStreamableIn;

import std;
import :concepts.StreamableIn;

export namespace xieite::traits {
	template<typename Type>
	struct IsStreamableIn
	: std::bool_constant<xieite::concepts::StreamableIn<Type>> {};
}
