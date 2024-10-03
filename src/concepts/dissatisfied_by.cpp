export module xieite:concepts.DissatisfiedBy;

import :concepts.SatisfiedBy;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept DissatisfiedBy = !xieite::concepts::SatisfiedBy<validator, Types...>;
}
