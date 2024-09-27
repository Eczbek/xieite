export module xieite:concepts.SatisfiesAll;

import :concepts.Satisfies;

export namespace xieite::concepts {
	template<typename Type, auto... validators>
	concept SatisfiesAll = (... && xieite::concepts::Satisfies<Type, validators>);
}
