export module xieite:traits.IsSpecializationOfAny;

import std;
import :concepts.SpecializationOfAny;

export namespace xieite::traits {
	template<typename Type, template<typename...> typename... Templates>
	struct IsSpecializationOfAny
	: std::bool_constant<xieite::concepts::SpecializationOfAny<Type, Templates...>> {};
}
