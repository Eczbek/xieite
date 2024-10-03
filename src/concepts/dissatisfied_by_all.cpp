export module xieite:concepts.DissatisfiedByAll;

import :concepts.SatisfiedByAll;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept DissatisfiedByAll = !xieite::concepts::SatisfiedByAll<validator, Types...>;
}
