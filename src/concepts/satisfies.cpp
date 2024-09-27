export module xieite:concepts.Satisfies;

import :concepts.SatisfiedBy;

export namespace xieite::concepts {
	template<typename Type, auto validator>
	concept Satisfies = xieite::concepts::SatisfiedBy<validator, Type>;
}
