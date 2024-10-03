export module xieite:concepts.Dissatisfies;

import :concepts.Satisfies;

export namespace xieite::concepts {
	template<typename Type, auto validator>
	concept Dissatisfies = !xieite::concepts::Satisfies<Type, validator>;
}
