export module xieite:concepts.DissatisfiesAll;

import :concepts.SatisfiesAll;

export namespace xieite::concepts {
	template<typename Type, auto... validators>
	concept DissatisfiesAll = !xieite::concepts::SatisfiesAll<Type, validators...>;
}
