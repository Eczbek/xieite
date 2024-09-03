export module xieite:traits.IsStreamableOut;

import std;
import :concepts.StreamableOut;

export namespace xieite::traits {
	template<typename Type>
	struct IsStreamableOut
	: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
}
