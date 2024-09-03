export module xieite:concepts.SpecializationOfAll;

import :concepts.SpecializationOf;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Templates>
	concept SpecializationOfAll = (... && xieite::concepts::SpecializationOf<Type, Templates>);
}
