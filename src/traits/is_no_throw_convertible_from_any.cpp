export module xieite:traits.IsNoThrowConvertibleFromAny;

import std;
import :concepts.NoThrowConvertibleFromAny;

export namespace xieite::traits {
	template<typename Target, typename... Sources>
	struct IsNoThrowConvertibleFromAny
	: std::bool_constant<xieite::concepts::NoThrowConvertibleFromAny<Target, Sources...>> {};
}
