export module xieite:concepts.DissatisfiedByAny;

import :concepts.SatisfiedByAny;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept DissatisfiedByAny = !xieite::concepts::SatisfiedByAny<validator, Types...>;
}
