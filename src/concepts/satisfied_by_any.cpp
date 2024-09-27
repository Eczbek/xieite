export module xieite:concepts.SatisfiedByAny;

import :concepts.SatisfiedBy;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept SatisfiedByAny = (... || xieite::concepts::SatisfiedBy<validator, Types>);
}
