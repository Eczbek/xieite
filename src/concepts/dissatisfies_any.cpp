export module xieite:concepts.DissatisfiesAny;

import :concepts.SatisfiesAny;

export namespace xieite::concepts {
	template<typename Type, auto... validators>
	concept DissatisfiesAny = !xieite::concepts::SatisfiesAny<Type, validators...>;
}
