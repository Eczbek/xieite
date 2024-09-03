export module xieite:traits.IsSpecializationOfAll;

import std;
import :concepts.SpecializationOfAll;

export namespace xieite::traits {
	template<typename Type, template<typename...> typename... Templates>
	struct IsSpecializationOfAll
	: std::bool_constant<xieite::concepts::SpecializationOfAll<Type, Templates...>> {};
}
