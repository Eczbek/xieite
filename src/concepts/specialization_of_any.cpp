export module xieite:concepts.SpecializationOfAny;

import :concepts.SpecializationOf;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Templates>
	concept SpecializationOfAny = (... || xieite::concepts::SpecializationOf<Type, Templates>);
}
