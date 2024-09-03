export module xieite:traits.IsNoThrowConvertibleToAll;

import std;
import :concepts.NoThrowConvertibleToAll;

export namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
}
