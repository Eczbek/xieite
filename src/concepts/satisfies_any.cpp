export module xieite:concepts.SatisfiesAny;

import :concepts.Satisfies;

export namespace xieite::concepts {
	template<typename Type, auto... validators>
	concept SatisfiesAny = (... || xieite::concepts::Satisfied<Type, validators>);
}
