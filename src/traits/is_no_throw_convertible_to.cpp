export module xieite:traits.IsNoThrowConvertibleTo;

import std;
import :concepts.NoThrowConvertibleTo;

export namespace xieite::traits {
	template<typename Source, typename Target>
	struct IsNoThrowConvertibleTo
	: std::bool_constant<xieite::concepts::NoThrowConvertibleTo<Source, Target>> {};
}
