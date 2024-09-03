export module xieite:traits.IsAny;

import std;
import :concepts.Any;

export namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAny
	: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
}
