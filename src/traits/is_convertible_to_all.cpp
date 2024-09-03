export module xieite:traits.IsConvertibleToAll;

import std;
import :concepts.ConvertibleToAll;

export namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToAll
	: std::bool_constant<xieite::concepts::ConvertibleToAll<Source, Targets...>> {};
}
