export module xieite:traits.IsOutputStream;

import std;
import :concepts.OutputStream;

export namespace xieite::traits {
	template<typename Type>
	struct IsOutputStream
	: std::bool_constant<xieite::concepts::OutputStream<Type>> {};
}
