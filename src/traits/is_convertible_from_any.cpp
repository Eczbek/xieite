export module xieite:traits.IsConvertibleFromAny;

import std;
import :concepts.ConvertibleFromAny;

export namespace xieite::traits {
	template<typename Target, typename... Sources>
	struct IsConvertibleFromAny
	: std::bool_constant<xieite::concepts::ConvertibleFromAny<Target, Sources...>> {};
}
