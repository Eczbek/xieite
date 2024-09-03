export module xieite:traits.IsInputStream;

import std;
import :concepts.InputStream;

export namespace xieite::traits {
	template<typename Type>
	struct IsInputStream
	: std::bool_constant<xieite::concepts::InputStream<Type>> {};
}
