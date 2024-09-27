export module xieite:concepts.SatisfiedByAll;

import :concepts.SatisfiedBy;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept SatisfiedByAll = (... && xieite::concepts::SatisfiedBy<validator, Types>);
}
