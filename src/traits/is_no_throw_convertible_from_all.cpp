export module xieite:traits.IsNoThrowConvertibleFromAll;

import std;
import :concepts.NoThrowConvertibleFromAll;

export namespace xieite::traits {
	template<typename Target, typename... Sources>
	struct IsNoThrowConvertibleFromAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleFromAll<Target, Sources...>> {};
}
